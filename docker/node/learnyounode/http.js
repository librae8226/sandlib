var http = require('http');
url = process.argv[2];
http.get(url, function(res) {
	//console.log("Got response: " + res.statusCode);
	res.setEncoding('utf8');
	res.on('data', console.log);
	res.on('error', console.error);
}).on('error', function(e) {
	console.log("Got error: " + e.message);
});
