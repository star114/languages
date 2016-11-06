/**
 * server.js
 * author - star114
 */

var http = require('http');
var socket_io = require('socket.io');
var fs = require('fs');


function handler(req, res) {
	fs.readFile(__dirname + '/client.html',
	function(err, data) {
		if(err){
			res.writeHead(500);
			return res.end('Error loading index.html');
		}
		res.writeHead(200);
		res.end(data);
	});
}

var app = http.createServer(handler);
var io = socket_io.listen(app);
app.listen(8000);

io.sockets.on('connection', function (socket) {
	socket.emit('news', {hello: 'world'});
	socket.on('my other event', function(data) {
		console.log(data);
	});
});
