/**
 * New node file
 * hello-world-mongodb.js
 * author - star114
 */

// mongoose package.json npm install failed.
// dependency : kerberos, bson < mongodb < mongoose
// but, kerberos and bson must be executed by shell. (by running build script)
// get mongodb connection
var mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/test');

var db = mongoose.connection;

db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function callback(){
	// success
	console.log('Connection Success');
	
	var kittySchema = mongoose.Schema({
		name : String
	});
	kittySchema.methods.speak = function(){
		var greeting = this.name ? "Meow name is " + this.name : "I don't have a name.";
		console.log(greeting);
	};
	
	var Kitten = mongoose.model('Kitten', kittySchema);
	
	var fluffy = new Kitten({
		name : 'fluffy'
	});
	
	fluffy.speak();
	
	fluffy.save(function(err, fluffy){
		if (err){
			// TODO handle the error
			throw err;
		}
	});
	
	Kitten.find(function(err, kittens) {
		if(err){
			// TODO handle the error
			throw err;
		}
		db.close();
		console.log('Kittens : ' + kittens);
	});
});