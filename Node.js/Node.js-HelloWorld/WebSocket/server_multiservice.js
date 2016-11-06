/**
 * server_multiservice.js
 * autor - star114
 */

var io = require('socket.io').listen(8000);

var chat = io.of('/chat').on('connection', function(socket) {
	socket.emit('a message', {
		that : 'only',
		'/chat' : 'will get'
	});
	chat.emit('a message', {
		everyone : 'in',
		'/chat' : 'will get'
	});
	socket.on('connect', function (data) {
		console.log(data);
	});
});

var news = io.of('/news').on('connection', function(socket) {
	socket.emit('item', {
		news : 'item' 
	});

	socket.on('news', function (data) {
		console.log(data);
	});
});
