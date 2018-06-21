var log = require('tracer-log');
var exec = require('child-process-promise').exec;
var cmd = 'npm --registry=https://registry.npm.taobao.org --disturl=https://npm.taobao.org/dist install --prefix /home/librae/work/sandlib/docker/node/npm-command-install/targetdir';

exec(cmd).then(function (result) {
  var stdout = result.stdout;
  var stderr = result.stderr;
  log.info("done: " + stdout);
}).catch(function (err) {
  log.error(err);
});
