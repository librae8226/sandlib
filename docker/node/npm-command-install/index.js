var exec = require('./promised-exec');
//var cmd = 'npm --registry=https://registry.npm.taobao.org --disturl=https://npm.taobao.org/dist install --prefix /home/librae/work/sandlib/docker/node/npm-command-install/targetdir';
var cmd = 'ls ~';

exec(cmd).then(function onResolved(res) {
  console.log("resolved: " + res);
}, function onRejected(err) {
  console.log("rejected: " + err);
});
