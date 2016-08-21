fs = require('fs');
var path = require('path');
var dir = process.argv[2];
var ext = '.' + process.argv[3];
//console.log(dir);
//console.log(ext);
fs.readdir(dir, function(err, list) {
	if (err) {
		throw err;
	} else {
/* filter
//		console.log(list);
		var filtered = list.filter(function(file) {
			var tmp = file.split('.');
			return tmp[1] === ext;
		});
//		console.log(filtered);
		filtered.forEach(function(result) {
			console.log(result);
		});
*/
/* extname */
		list.forEach(function(file) {
			if (path.extname(file) === ext) {
				console.log(file);
			}
		});
	}
});
