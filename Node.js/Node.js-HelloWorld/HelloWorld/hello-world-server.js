var http = require('http');
http.createServer(function handler(req, res) {
//  // Build the answer
//	var answer = "";
//	answer += "Request URL: " + req.url + "\n";
//	answer += "Request type: " + req.method + "\n";
//	answer += "Request headers: " + JSON.stringify(req.headers) + "\n";
//	
//	// Send answer
//	res.writeHead(200, {'Content-Type': 'text/plain'});
//    res.end('Hello World\n\n' + answer);
	
	//Main page
	if (req.url == "/"){
		res.writeHead(200, {
			"Content-Type" : "text/html"
		});
		res.end("Welcome to the Lucas's World!!");
	}
	// About page
	else if (req.url == "/about"){
		res.writeHead(200, {
			"Content-Type" : "text/html"
		});
		res.end("Welcome to the about page!! I will show you something...");
	}
	// File not found
	else {
		res.writeHead(404, {
			"Content-Type" : "text/html"
		});
		res.end("Oops, 404 Error!! File not found.");
	}
}).listen(1337, '127.0.0.1');
console.log('Server running at http://127.0.0.1:1337/');
