var TinyString = require('../');
var assert = require('assert');

describe('tinystring', function () {
  it('should initialize with a string', function () {
    assert.equal(new TinyString('test').value(), 'test');
  });

  it('should append strings', function() {
    var str = new TinyString('test');

    str.append('1');
    str.append('2');
    str.append('3');
    str.append('4');

    str.append('5')
       .append('6')
       .append('7')
       .append('8');

    assert.equal(str.value(), 'test12345678');
    assert.equal(str.value().length, 12);
  });

  it('should append many strings', function () {
    var base = 'This is a test string';

    var str = new TinyString();

    for (var i = 0; i < 5000; ++i) {
      str.append(i + ' : ' + base);
    }

    assert.equal(str.value().length, 138890);
  });
});
