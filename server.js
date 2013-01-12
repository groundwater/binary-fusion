var net  = require('net')
var util = require('util')

var sock = new net.Socket({fd:0});

// console.log(sock)

var serv = new net.createServer(function(socket){
    var pid = util.format('%d',process.pid);
    socket.end(pid);
})

serv.listen({fd:3})

// console.log(serv)

console.log('Listening')
