# tinystring [![Build Status](https://travis-ci.org/zhm/tinystring.svg?branch=master)](https://travis-ci.org/zhm/tinystring)

A tiny wrapper around std::stringstream.

## Installation

```sh
npm install tinystring
```

## Performance

The goal is to minimize the memory usage when building up huge strings. In most cases using a stream is a better design, but this is for cases where that might not be possible.

```js
var base = 'This is a test string';

var str = '';

for (var i = 0; i < 8000000; ++i) {
  str += (i + ' : ' + base);
}

-builtin-
total: 1.2 GB
heapTotal: 1.1 GB
heapUsed: 1013.7 MB

-tinystring-
total: 402 MB
heapTotal: 28.8 MB
heapUsed: 22.9 MB
```


