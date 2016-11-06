/**
 * New node file
 * read-file.js
 * author - star114
 */

var fs = require('fs');

fs.readFile("persistData.txt", 'utf-8', function(err, data){
	if (!err){
		console.log("Read persistent data successfully!!\r\n");
		console.log(data);
	} else {
		throw err;
	}
});
