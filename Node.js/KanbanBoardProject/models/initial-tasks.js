/**
 * initial-tasks.js
 * author - star114
 */

exports.getTasks = function() {
	var tasks = {
		todo: [ "design model", "integration test" ],
		inProgress: [ "develop main page" ],
		done: [ "design main page" ]
	};
	return tasks;
};
