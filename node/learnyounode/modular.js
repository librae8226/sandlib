var m = require('./my-module.js');

var dir = process.argv[2];
var ext = process.argv[3];

//m.ls_filtered(dir, ext, function(err, data) {
m(dir, ext, function(err, list) {
	if (err) {
		return console.error('There was an error:', err);
	}

	list.forEach(function (file) {
		console.log(file);
	})
});
