unixid = require('userid');
console.log(unixid.uid(process.env.USER));
console.log(unixid.gid('node-red'));
