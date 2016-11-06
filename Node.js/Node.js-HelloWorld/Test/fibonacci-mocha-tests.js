/**
 * New node file
 * fibonacci-mocha-tests.js
 * author - star114
 */

var fibonacci = require('../fibonacci'),
	assert = require('assert');
describe('Getting Fibonaccie Number >>', function() {
	describe('when trying to get fibonacci 8th number', function() {
		it('shuld return 13', 
				function() {
					assert.equal(fibonacci.getFibonacciNumber(8), 13, 'Wrong Fibonacci!!');
				}
		)
	})
}
)

