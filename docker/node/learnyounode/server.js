const http = require('http');
const strftime = require('strftime');

const hostname = '0.0.0.0';
const port = 8080;

const server = http.createServer((req, res) => {
	res.statusCode = 200;
	res.setHeader('Content-Type', 'text/plain');
	res.write(strftime('%Y-%m-%d %H:%M:%S') + '\n');
	res.end('Hello World\n');
});

server.listen(port, hostname, () => {
	console.log(`Server running at http://${hostname}:${port}/`);
});
