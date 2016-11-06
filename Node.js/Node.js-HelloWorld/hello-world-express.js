/*
 * hello-world-express.js
 * author - star114
 * using express.
 */

// express module must be installed by npm
// package.json -> dependency : express! 
var express = require('express'),
	http = require('http');
var app = express();
var logger = require('morgan');

//// Using default logger
app.use(logger());

app.all("*", function (request, response, next){
	response.writeHead(200, {'Content-Type': 'text/plain'});
	next();
});

app.get("/", function(request, response){
	response.end("Welcome to the homepage!");
});

app.get("/about", function(request, response){
	response.end("Welcome to the about page!");
});

app.get("/hi/:user", function(request, response){
	response.end("Hi, "+ request.params.user + ".");
});

app.get("*", function(request, response){
	response.end("404 error!");
});

http.createServer(app).listen(1337, '127.0.0.1');

console.log('Server running at http://127.0.0.1:1337/');
