//console.log(process.argv.length);
var sum = 0;
for (var i = 2; i < process.argv.length; i++) {
	sum += parseInt(process.argv[i]);
}
console.log(sum);
