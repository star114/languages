/*
 * hello-world-server.js
 * author - star114
 * using connect, middleware.
 */

// connect module must be installed by npm
// package.json -> dependency : connect! 
var connect = require('connect'),
	http = require('http');
var app = connect();
var logger = require('morgan');

//// Logging middleware
//app.use(function(request, response, next){
//	console.log("In comes a " + request.method + " to " + request.url);
//	
//	// if there is not next function, server cannot respond to client.
//	next();
//});

// connect does not have logger() function.
// http://stackoverflow.com/questions/24692435/nodejs-connect-error-has-no-method-logger
//app.use(connect.logger());

//// Using default logger
app.use(logger());

/// Main page
app.use(function (req, res, next){
	if (req.url == "/"){
		res.writeHead(200, {"Content-Type": "text/plain"});
		res.end("Welcome to the homepage!\n");
		// The middleware stops here.
	} else {
		next();
	}
});

/// About page
app.use(function (req, res, next){
	if (req.url == "/about"){
		res.writeHead(200, {"Content-Type": "text/plain"});
		res.end("Welcome to the about page!\n");
		// The middleware stops here.
	} else {
		next();
	}
});

/// 404 Error page
app.use(function (req, res) {
	res.writeHead(200, {"Content-Type" : "text/plain"});
	res.end("404 error!\n");
});

// Send "Hello World"
app.use(function (req, res){
	res.writeHead(200, {'Content-Type': 'text/plain'});
	res.end('Hello World\n');
});

http.createServer(app).listen(1337, '127.0.0.1');

console.log('Server running at http://127.0.0.1:1337/');
