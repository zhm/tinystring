var pretty = require('prettysize');

function builtin() {
  var base = 'This is a test string';

  var str = '';

  for (var i = 0; i < 8000000; ++i) {
    str += (i + ' : ' + base);
  }

  var usage = process.memoryUsage();

  console.log('-builtin- (' + str.length + ')');
  console.log('total: ' + pretty(usage.rss));
  console.log('heapTotal: ' + pretty(usage.heapTotal));
  console.log('heapUsed: ' + pretty(usage.heapUsed));
}

builtin();
