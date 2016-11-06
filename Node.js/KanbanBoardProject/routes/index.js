var express = require('express');
var router = express.Router();

//var controllers = require('../controllers/index');
///* GET home page. */
//router.get('/', function(req, res) {
//	controllers.index(req,res);
//});


var task = require('../controllers/task-controller.js');
router.get('/', function(req, res) {
	task.list(req, res);
});
router.post('/createTask', function(req, res) {
	task.create(req, res);
});
router.post('/updateTask', function(req, res) {
	task.update(req, res);
});
router.post('/removeTask', function(req, res) {
	task.remove(req, res);
});


module.exports = router;
