require('shelljs/global');
var express = require('express');
var router = express.Router();
var app = express();

app.use('/', router);
router.post('/reload', function(req, res) {
  var r = {result: true};
  var out = exec('nginx -s reload', function(code, stdout, stderr) {
    if (code != 0) {
      r.result = false;
      r.err = stderr;
    }
    res.send(r);
  });
});

app.listen(4999, 'localhost');
