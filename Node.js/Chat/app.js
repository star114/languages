var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');

var routes = require('./routes/index');
var users = require('./routes/users');

var app = express();

var fs = require('fs');
var path = require('path');

var server = require('http').createServer(app);
var io = require('socket.io').listen(server);

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

// uncomment after placing your favicon in /public
app.use(favicon(__dirname + '/public/favicon.ico'));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', routes);
app.use('/users', users);

app.start = app.listen = app.aaa = function(){
	return server.listen.apply(server, arguments)
}

// Service File Include Function
function include (filename_) {
	with (global) {
		eval(fs.readFileSync(filename_) + '', "UTF-8");
	}
}
console.log(fs.readFileSync(__dirname + "/config/include.js", "UTF-8"));
//eval(fs.readFileSync(__dirname + "/config/include.js", "UTF-8"));
//include (__dirname +"/config/include.js");
var include_ = require('./config/include.js');

var roomnames = {};
var nicknames = {};
var participated = {};
//function 
for (var i =0 ; i < include_.servicefile.length; i++) {
	include(__dirname + "/service/" + include_.servicefile[i]);
}

app.all('*', function(req, res, next) {
	res.header("Access-Control-Allow-Origin", "*");
	res.header("Access-Control-Allow-Headers", "X-Requested-With");
	next();
});

// catch 404 and forward to error handler
app.use(function(req, res, next) {
	var err = new Error('Not Found');
    err.status = 404;
    next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
    app.use(function(err, req, res, next) {
        res.status(err.status || 500);
        res.render('error', {
            message: err.message,
            error: err
        });
    });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
        message: err.message,
        error: {}
    });
});


module.exports = app;
