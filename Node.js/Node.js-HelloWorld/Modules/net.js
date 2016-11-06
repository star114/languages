/**
 * New node file
 * net.js
 * author - star114
 * how to connect to server
 * $ telnet localhost 8124
 */
var net = require('net');

// create server
var server = net.createServer(function(c) { //'connection' listener
	console.log('server connected');
	// disconnecting server message 
	c.on('end', function(){
		console.log('server disconnected');
	});
	// client message when connected.
	c.write('hello\r\nThis is My Telnet Service\r\n');
	c.pipe(c);
});

// start server
server.listen(8124, function(){ // 'listening' listener
	console.log('server bound');
});


