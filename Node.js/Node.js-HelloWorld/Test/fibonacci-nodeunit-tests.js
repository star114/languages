/**
 * New node file
 * fibonacci-nodeunit-tests.js
 * author - star114
 */

var fibonacci = require('../fibonacci');

exports.testGetFibonacciNumber = function(test) {
	test.expect(3);
	test.equal(fibonacci.getFibonacciNumber(8), 13,
			'Wrong fibonacci!! 8th fibonacci number is 13!!');
	test.equal(fibonacci.getFibonacciNumber(9), 21,
			'Wrong fibonacci!! 8th fibonacci number is 21!!');
	test.equal(fibonacci.getFibonacciNumber(10), 34,
			'Wrong fibonacci!! 10th fibonacci number is 34!!');
	//test.expect(1);
	//test.ok(true, "this assertion should pass");
	//test.equal(true, true, "this assertion should pass");
	test.done();
//	console.log("test " + fibonacci.getFibonacciNumber(9));
};
