/**
 * New node file
 * global.js
 * author - star114
 */

console.log("__filename : ", __filename);
console.log("__dirname : ", __dirname);
//console.log("process : ", process);

process.argv.forEach(function(val, index, array) {
	console.log(index + ": " + val);
});

console.log("process.execPath : ", process.execPath);
console.log("process.cwd() : ", process.cwd());
console.log("process.version : ", process.version);
console.log("process.memoryUsage : ", process.memoryUsage());
console.log("process.env : ", process.env);