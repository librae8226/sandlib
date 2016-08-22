var net = require('net')

var strftime = require('strftime')
//console.log(strftime('%Y-%M-%d %H:%M'))

var server = net.createServer(function (socket) {
	socket.write(strftime('%Y-%m-%d %H:%M') + '\n')
	socket.end();
});
server.listen(Number(process.argv[2]));
