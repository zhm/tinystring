var exec = require('child_process').execSync;

var arg = process.argv[1];

var output = {stdio: [0, 1, 2]};

if (arg === 'tinystring') {
  exec('node ./benchmark-tinystring.js', output);
} else if (arg === 'builtin') {
  exec('node ./benchmark-builtin.js', output);
} else {
  exec('node ./benchmark-builtin.js', output);
  exec('node ./benchmark-tinystring.js', output);
}
