var fs = require('fs');
var path = require('path');

//exports.ls_filtered = ls_filtered;
//function ls_filtered(dir, ext, callback) {
module.exports = function(dir, ext, callback) {
	fs.readdir(dir, function(err, list) {
		if (err) {
			return callback(err);
		}
		var filtered = list.filter(function(file) {
			return path.extname(file) === '.' + ext;
		});
		callback(null, filtered);
	});
}
