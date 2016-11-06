/**
 * server_with_express.js
 * author - star114
 */

var express = require('express');
var app = express();
var http = require ('http');
var server = http.createServer(app);
var io = require('socket.io').listen(server);

server.listen(8000);

app.get('/', function (req, res) {
	res.sendfile(__dirname + '/client_with_express.html');
});

// socket.io event handling
io.sockets.on('connection', function( socket ) {
	socket.emit('news', {hello:'world'});
	socket.on('my other event', function (data) {
		console.log(data);
	});
	socket.on('private message', function(from, msg){
		console.log('I received a private message by ' , from, ' saying ', msg);
	});
});
io.sockets.on('disconnection', function () {
	io.sockets.emit('user disconnected');
});

