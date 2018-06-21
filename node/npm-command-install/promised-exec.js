var when = require('when');
var exec = require('child_process').exec;

var promised_exec = function(cmd) {
  return when.promise(function(resolve, reject) {
    var out = exec(cmd, function(error, stdout, stderr) {
      if (error) {
        // need to be handled by caller
        reject(error);
      } else {
        resolve(true);
      }
    });

    out.stdout.on('data', console.log);
  });
}

module.exports = promised_exec;
