/**
 * New node file
 * url.js
 * author - star114
 */

var url = require('url');

var obj = url.parse('https://www.google.co.kr/search?q=node.js+on+addListener&oq=node.js');
console.log('url to Object : ', obj);
console.log('======================');
console.log('Object to Url : ', url.format(obj));