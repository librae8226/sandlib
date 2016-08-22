var http = require('http');
var bl = require('bl');

url = process.argv[2];
http.get(url, function(res) {
	res.pipe(bl(function (err, data) {
		if (err)
			throw err;
		var r = data.toString();
		console.log(r.length);
		console.log(r);
	}));
}).on('error', function(e) {
	console.log("Got error: " + e.message);
});
