/**
 * New node file
 * event.js
 * author - star114
 */

var eventHandler = function(){
	console.log('EXIT');
};
process.addListener('exit', eventHandler);
//process.on('exit', eventHandler);

// event handler to register limits 10.
// Using setMaxListeners(n) , you can register over limits.

console.log("Before Exit");

var errHandler = function(e){
	console.log("err1", e);
};
var errHandler2 = function(e){
	console.log("err2", e);
};

process.on('uncaughtException', errHandler);
process.on('uncaughtException', errHandler2);

process.removeListener('uncaughtException', errHandler2);

//process.removeAllListeners('uncaughtException');

//occur error! undefined value.
error;