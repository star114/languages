/**
 * New node file
 * fibonacci.js
 * author - star114
 */

function getFibonacciNumber(total)
{
	console.time('Getting Fibonacci Numbers');
	
	console.log("Let's get Fibonacci Numbers");
	
	var results = [0,1];
	
	for ( var i = 0 ; i < total; i ++){
		if (i >= 2){
			results.push(results[i -2] + results[i -1]);
		}
	}
	
	console.log("Fibonacci [" + total + "] th Number is [" + 
			results[total -1] + "]");
	console.log("All numbers are [" + results + "]");
	
	console.timeEnd('Getting Fibonacci Numbers');
	
	return results[total-1];
}

module.exports.getFibonacciNumber = getFibonacciNumber;