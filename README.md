## Application Container

### Manager

- start/stop/restart processes
- send signal to processes (e.g. SIGINT)
- set/get environment variables
- set port numbers
- provide pre-opened sockets

### Supervisor

- restart process on crash
- throttle restart if process is thrashing
- log exit codes

### Monitor

- collect `STDOUT` and `STDERR` for each process


