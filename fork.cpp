#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <signal.h>

void signal_callback_handler(int signum)
{
   printf("Caught signal %d\n",signum);
}

int main(int argc, char **argv, char **envp)
{
  
  signal(SIGCHLD, signal_callback_handler);
  
  struct sockaddr_in server;
  int sock_desc, k;
  
  sock_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_desc < 0)
  {
    exit(-1);
  }
  
  char * port_env = getenv("PORT");
  int port;
  if(port_env == NULL)
  {
    port = 8888;
  }
  else
  {
    port = strtol( port_env, NULL, 10 );
  }
  
  server.sin_family = AF_INET; 
  server.sin_addr.s_addr = inet_addr("0.0.0.0"); 
  server.sin_port = htons( port );
  
  k = bind(sock_desc,(struct sockaddr*)&server, sizeof(server));
  if( k < 0 )
  {
    printf("Failed to Bind");
    exit(-2);
  }
  
  k = listen(sock_desc,5);
  if (k < 0 )
  {
    printf("Listen Failed");
    exit(-3);
  }
  
  printf("Spwaning...\n");
  
  int pid;
  
  for(int i=0; i<4; i++)
  {
    
    pid = fork();
    
    if(pid==0)
    {
      printf("Child Starting\n");
      
      char * command = argv[1];
      char * pargs[3];
      
      pargs[0] = argv[1];
      pargs[1] = argv[2];
      pargs[2] = '\0';
      
      int code = execvp(command,pargs);
      exit(code);
    }
    else
    {
      printf("Socket Opened: %d\n", sock_desc);
    }
  }
  int status;
  
  while(true){
    int status;
    wait(&status);
    printf("Child Exited With Status %d",status);
  }
}
