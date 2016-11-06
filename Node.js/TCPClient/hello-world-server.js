var http = require('http');
var client = require('net').Socket();
var fromServer = '';

client.connect(15001, function() {
	console.log('Connected successfully!!');
});

// When I Get 'data' from server, put 'data' in 'message' to send in response
client.on('data', function(data) {
	console.log('Recieve data: '+ data);
	fromServer = data;
})

//Add a 'close' event handler for the client socket
client.on('close', function() {
	console.log('Connection closed.');
	client.destroy();
});

http.createServer(function handler(req, res) {
	// ignore favicon.ico request
	if (req.url === '/favicon.ico'){
		res.writeHead(200, {'Content-Type': 'image/x-icon'});
		res.end();
		return;
	}
	
	// Write a message to the Socket
	
	client.write('Who\'s there?\n', function() {
		console.log('Write data successfully!!');
	});
	
	res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('Hello World\n' + fromServer);
}).listen(1337, '127.0.0.1');
console.log('Server running at http://127.0.0.1:1337/');
