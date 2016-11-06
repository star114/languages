/**
 * New node file
 * exportsTest.js
 * author - star114
 */

// I can be use 'cal.js' when there is cal.js file in node_modules directory.
// If there is not cal.js file, this could be compile error.
// Then, we can use '.cal.js' when cal.js file is in the same directory.

var cal = require('cal.js');

console.log(cal.sum(5,6));
