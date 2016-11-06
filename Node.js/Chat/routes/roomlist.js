var express = require('express');
var router = express.Router();

/* GET room listing. */
router.get('/', function(req, res) {
	res.send(io.sockets.adapter.rooms);
});

module.exports = router;
