var express = require('express');
var router = express.Router();
var app = express();
var httpProxy = require('http-proxy');

app.all('/*', function(req, res, next) {
  var subdomain = req.subdomains[0];
  if (!subdomain) {
    next();
  } else {
    console.log(subdomain);
    var proxy_host = 'blab.cloudred.cc';
    var proxy_port = 50080;
    console.log("proxy pass:", proxy_host, "port:", proxy_port);
    var proxy = httpProxy.createProxyServer({
      target: {
        host: proxy_host,
        port: proxy_port
      }
    });
    proxy.web(req, res);
  }
});

app.use('/', router);
router.get('/', function(req, res) {
  res.send('the root');
});

app.listen(5000);
