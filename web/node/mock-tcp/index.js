const m = require('./machine')
var n = process.argv[2];

n = parseInt(n);

if (!n || n > 1000) {
  n = 1;
}

for (var i = 0; i < n; i++) {
  setTimeout(function () {
    m.start();
  }, Math.random()*2000);
}
