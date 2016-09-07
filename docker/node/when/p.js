var when = require('when');

function a(val) {
  return when.promise(function(resolve, reject) {
    console.log('a: ' + val);
    resolve('a-resolve');
    //reject('a-reject');
  });
}

function b(val) {
  return when.promise(function(resolve, reject) {
    console.log('b: ' + val);
    resolve('b-resolve');
    //reject('b-reject');
  });
}

function c(val) {
  return when.promise(function(resolve, reject) {
    console.log('c: ' + val);
    resolve('c-resolve');
    //reject('c-reject');
  });
}

a('init').then(b).then(c).then(function onResolved(val) {
  console.log('resolved: ' + val);
}, function onRejected(err) {
  console.log('rejected: ' + err)
});
