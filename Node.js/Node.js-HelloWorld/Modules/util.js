/**
 * New node file
 * util.js
 * author - star114
 */
var util = require('util');
var data = util.format('%s , %d, %j', 'foo', 10, {name:'node.js'});
util.log(data);

util.log('Timestamped message.');
