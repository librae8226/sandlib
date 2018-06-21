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

async.map(url, httpGetCollect, function(err, results) {
//	console.log(results);
	results.forEach(function(data) {
		console.log(data);
	});
});
