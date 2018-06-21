module.exports = {
  files: {
    javascripts: {
      joinTo: {
        'vendor.js': /^(?!app)/,
        'app.js': /^app/
      }
    },
    stylesheets: {joinTo: 'app.css'}
  },

  server: {
    port: 8080,
    hostname: '0.0.0.0',
    stripSlashes: true
  },

  plugins: {
    babel: {presets: ['es2015', 'react']}
  }
};
