var pretty = require('prettysize');
var TinyString = require('../');

function tinystring() {
  var base = 'This is a test string';

  var str = new TinyString();

  for (var i = 0; i < 8000000; ++i) {
    str.append(i + ' : ' + base);
  }

  var usage = process.memoryUsage();

  console.log('-tinystring- (' + str.value().length + ')');
  console.log('total: ' + pretty(usage.rss));
  console.log('heapTotal: ' + pretty(usage.heapTotal));
  console.log('heapUsed: ' + pretty(usage.heapUsed));
}

tinystring();
