var request = require('request')
var username = process.argv[3];
var password = process.argv[4];
var options = {
  url: process.argv[2],
  method: 'post',
  auth: {
    user: username,
    password: password
  },
  json: {
    machines: ['37188', '37100', '39000'],
  }
}

request(options, function (err, res, body) {
  if (err) {
    console.dir(err)
    return
  }
  console.dir('headers', res.headers)
  console.dir('status code', res.statusCode)
  console.dir(body)
})
