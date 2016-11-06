/**
 * New node file
 * write-file.js
 * author - star114
 */

var fs = require('fs'),
	data = "I love Node.js!!";

fs.writeFile("persistData.txt", data, 'utf-8', function(err){
	if (!err){
		console.log("I just persist data in file successfully!!");
	} else {
		throw err;
	}
} );
