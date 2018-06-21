var fs = require('fs');
//var buf = fs.readFileSync('/home/librae/data/learnyounode/baby-steps.js');
var buf = fs.readFileSync(process.argv[2]);
var lines = buf.toString().split('\n');
//console.log(lines);
//console.log(lines.length);
console.log(lines.length - 1);
