/**
 * New node file
 * fibonacci-test.js
 * author - star114.
 */

var fibonacci = require('../fibonacci');
var assert = require('assert');

assert.equal(fibonacci.getFibonacciNumber(10), 34, 'Wrong fibonacci!!');