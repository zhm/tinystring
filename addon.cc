#include "tinystring.h"

using v8::FunctionTemplate;

NAN_MODULE_INIT(Init) {
  TinyString::Init(target);
}

NODE_MODULE(tinystring, Init)
