var http = require('http');
var bl = require('bl');
var async = require('async');

var url = [];
var result;

function httpGetCollect(url, callback) {
	http.get(url, function(res) {
		res.pipe(bl(function (err, data) {
			if (err)
				throw err;
			result = data.toString();
			callback(null, result);
		}));
	}).on('error', function(e) {
		console.log("Got error: " + e.message);
	});
}

for (var i = 0; i < 3; i++) {
	url[i] = process.argv[2 + i];
}
//console.log(url);

async.parallel([
	function(callback) {
		httpGetCollect(url[0], callback);
	},
	function(callback) {
		httpGetCollect(url[1], callback);
	},
	function(callback) {
		httpGetCollect(url[2], callback);
	}
], function(err, results) {
	if (err)
		throw err;
//	console.log(results);
	results.forEach(function(data) {
		console.log(data);
	});
});
