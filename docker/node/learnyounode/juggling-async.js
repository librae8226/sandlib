var http = require('http');
var bl = require('bl');

var url = [];
var result = [];
var count = 0;

for (var i = 0; i < 3; i++) {
	url[i] = process.argv[2 + i];
	httpGetCollect(i);
}

function printResult() {
	result.forEach(function(data) {
		console.log(data);
	});
}

function httpGetCollect(index) {
	http.get(url[index], function(res) {
		res.pipe(bl(function (err, data) {
			if (err)
				throw err;
			result[index] = data.toString();
			count++;
			if (count == 3)
				printResult();
		}));
	}).on('error', function(e) {
		console.log("Got error: " + e.message);
	});
}
