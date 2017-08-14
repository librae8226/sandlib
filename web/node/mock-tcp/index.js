const m = require('./machine')
var n = process.argv[2];
var sec = process.argv[3];

n = parseInt(n);
if (!n || n > 1000) {
  n = 1;
}

sec = parseInt(sec);
if (!sec) {
  sec = 45;
}

for (var i = 0; i < n; i++) {
  setTimeout(function () {
    m.start(sec);
  }, Math.random()*sec*1000);
}
