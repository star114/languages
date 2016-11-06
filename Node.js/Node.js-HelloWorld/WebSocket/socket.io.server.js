/**
 * socket.io.server.js
 * author - star114
 * simple echo server
 */
var io = require('socket.io').listen(8000);

io.sockets.on('connection', function(socket) {
	socket.on('msg', function(data) {
		console.log(data);
		setTimeout(function() {
			io.sockets.emit('msg_by_server', 'Server got your message : ' + data);
		}, 1000);
	});
});

