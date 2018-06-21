'use strict'

const childProcess = require('child_process')

function shellExec (cmd = '', opts = {}) {
  if (Array.isArray(cmd)) {
    cmd = cmd.join(';')
  }

  let child

  try {
    child = childProcess.spawn(cmd, opts)
  } catch (error) {
    return Promise.reject(error)
  }

  return new Promise(resolve => {
    let stdout = ''
    let stderr = ''

    if (child.stdout) {
      child.stdout.on('data', data => {
        stdout += data
      })
    }

    if (child.stderr) {
      child.stderr.on('data', data => {
        stderr += data
      })
    }

    child.on('error', error => {
      resolve({ error, stdout, stderr, cmd })
    })

    child.on('close', code => {
      resolve({ stdout, stderr, cmd, code })
    })
  })
}

shellExec('aos', ['devices']).then((res) => {
  console.log(JSON.parse(res.stdout))
}).catch((err) => {
  console.log(err)
})
