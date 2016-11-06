/**
 * task.js
 * author - star114
 */
// binding modules
var mongoose = require('mongoose');
var Schema = mongoose.Schema;

// declare task schema
var taskSchema = new Schema({
	status: { type: String, default: "TO-DO"},
	contents: String,
	createData: { type: Date, default: Date.now /*, default: Date.now*/},
	author: { type:String, default: "star114"}
});

// exports model for task-controller
module.exports = mongoose.model('Task', taskSchema);
