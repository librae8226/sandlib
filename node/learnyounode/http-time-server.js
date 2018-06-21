var http = require('http');
var fs = require('fs');
var strftime = require('strftime')

var server = http.createServer(function(req, res) {
  res.writeHead(200, {'content-type': 'text/plain'});
  res.end(strftime('%Y-%m-%d %H:%M:%S') + '\n');
})
server.listen(Number(process.argv[2]));
