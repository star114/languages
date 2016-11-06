/**
 * New node file
 * hello-world-client-post.js
 * author - star114
 */
var http = require('http');
var options = {
	hostname : '127.0.0.1',
	port : 1337,
	path : '/',
	method : 'POST'
};
var req = http.request(options, function(res){
	console.log('STATUS: ', res.statusCode);
	console.log('HEADERS: ', JSON.stringify(res.headers));
	res.setEncoding('utf8');
	res.on('data', function(chunk){
		console.log('BODY: ' + chunk);
	});
	req.on('error', function(e) {
		console.log('problem with request : ', e.message);
	});
});

//write data to request body
req.write('data\n');
req.write('data\n');
req.end();


http.get("http://www.google.com/index.html", function(res) {
	console.log("Got response: " + res.statusCode);
}).on('error', function(e){
	console.log("Got Error: " + e.message);
});