const net = require('net');
const PORT = 59100;
const HOST = 'txx.goiot.cc';

const TS = function() {
  let ts = (new Date()).toJSON();
  ts = ts.replace(/T/gi, ' ');
  ts = ts.replace(/Z/gi, '');
  return '[' + ts + ']';
}

const TAG = function(id) {
  return id.toString(16);
}

function unpack(raw) {
  let machine = {};
  // 2nd~10th byte: mid, but we only use 4 bytes from 7th~10th
  machine.mid = parseInt(raw.readUInt32BE(7));

  // 11th, 12th: vendor, model
  machine.vendor = parseInt(raw.readUInt8(11));
  machine.model = parseInt(raw.readUInt8(12));

  // 13th: cmd
  machine.cmd = parseInt(raw.readUInt8(13));

  return machine;
}

function machine(id) {
  this.data = {
    mid: id,
    name: "test machine ?",
    type: "washer",
    vendor: 1,
    model: 1
  };
}

machine.prototype.start = function(sec) {
  let m = this.data;
  var heartbeat;

  this.data.name = 'test machine ' + this.data.mid;

  let id = this.data.mid;

  const client = net.connect({port: PORT, host: HOST}, () => {
    console.log(TS(), TAG(id), 'connected');
    heartbeat = setInterval(function () {
      let buf = this.produce_buffer({replycmd: 0x0});
      client.write(buf);
      //console.log(TS(), TAG(id), buf.toJSON());
    }.bind(this), sec*1000);
  });

  client.on('end', () => {
    console.log(TS(), TAG(id), 'disconnected');
  });


  client.on('data', (data) => {
    //console.log(TS(), TAG(id), data.toString());
    console.log(TS(), TAG(id), data);
    if (data.toString() === 'close') {
      clearInterval(heartbeat);
      client.end();
    } else {
      if (data[0] == 0xaa && data.length >= 24) {
        let m = unpack(data);
        console.log(m);
        if (m.cmd == 3) {
          let buf = this.produce_buffer({replycmd: m.cmd});
          client.write(buf);
        }
      } else {
        console.log(TS(), TAG(id), 'unknown commands');
      }
    }
  });
}

machine.prototype.produce_buffer = function(param) {
  if (!param) {
    console.log(TS(), TAG(id), 'no param');
    return null;
  }

  // 帧头
  let preamble = Buffer.from([0xaa]);
  let len = Buffer.from([24]);

  // 编号
  if (!parseInt(param.mid)) {
    param.mid = this.data.mid;
  }
  let mid = Buffer.alloc(9);
  mid.writeUInt32BE(parseInt(param.mid), 5);

  // 厂商代码
  if (!parseInt(param.vendor)) {
    param.vendor = this.data.vendor;
  }
  let vendor = Buffer.alloc(1);
  vendor.writeUInt8(parseInt(param.vendor), 0);

  // 商品代码
  if (!parseInt(param.model)) {
    param.model = this.data.model;
  }
  let model = Buffer.alloc(1);
  model.writeUInt8(parseInt(param.model), 0);

  // 回复命令
  if (!parseInt(param.replycmd)) {
    param.replycmd = 0;
  }
  let replycmd = Buffer.alloc(1);
  replycmd.writeUInt8(parseInt(param.replycmd), 0);

  // CRC 应答
  let ack = Buffer.alloc(1);
  ack.writeUInt8(0x6, 0);

  // 模式
  if (!parseInt(param.mode)) {
    param.mode= 0;
  }
  let mode = Buffer.alloc(1);
  mode.writeUInt8(parseInt(param.mode), 0);

  // 状态
  if (!parseInt(param.status)) {
    param.status = 1;
  }
  let status = Buffer.alloc(1);
  status.writeUInt8(parseInt(param.status), 0);

  // 故障
  if (!parseInt(param.error)) {
    param.error = 0;
  }
  let error = Buffer.alloc(1);
  error.writeUInt8(parseInt(error), 0);

  // 剩余时间
  if (!parseInt(param.remain)) {
    param.remain = 0;
  }
  let remain = Buffer.alloc(1);
  remain.writeUInt8(parseInt(remain), 0);

  // 预留
  let reserved = Buffer.alloc(5);

  // CRC 校验
  let crc = Buffer.alloc(2);

  let buf = Buffer.concat([
      preamble,
      len,
      mid,
      vendor,
      model,
      replycmd,
      ack,
      mode,
      status,
      error,
      remain,
      reserved,
      crc
  ]);
  return buf;
}

module.exports = machine;
