/**
 * New node file
 * fs.js
 * author - star114
 */
var fs = require('fs');

//////////////
///  read  ///
//////////////
fs.readFile('test.txt', 'utf8', function(err, data){
	if (err) throw err;
	console.log(data);
});
//////////////
/// exists ///
//////////////
// unSync
fs.exists('test1.txt', function(exists) {
	console.log('test1.txt fs.exists : ', exists);
});

// Sync
var exists = fs.existsSync('test.txt');
console.log('test.txt fs.existsSync : ', exists);


//////////////
/// write  ///
//////////////
// unSync
fs.writeFile('message.txt', 'Hello Node.js', 'utf8', function(err){
	if(err) throw err;
	console.log('It\'s saved!');
});
// Sync
fs.writeFileSync('message1.txt', 'Hello Node.js 2', 'utf8');