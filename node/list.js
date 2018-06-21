#!/usr/bin/env node
'use strict';

const serialport = require('serialport');

serialport.list((err, ports) => {
    if (err) {
      console.error(JSON.stringify(err));
      return err;
    }
    console.log(JSON.stringify(ports));
});
