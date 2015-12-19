#ifndef __TINYSTRING_H__
#define __TINYSTRING_H__

#include <sstream>
#include <nan.h>

class TinyString : public Nan::ObjectWrap {
public:
  static void Init(v8::Local<v8::Object> exports);

private:
  explicit TinyString(const char *value);

  ~TinyString();

  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);

  static void GetValue(const Nan::FunctionCallbackInfo<v8::Value>& info);

  static void Append(const Nan::FunctionCallbackInfo<v8::Value>& info);

  static Nan::Persistent<v8::Function> constructor;

  std::stringstream value_;
};

#endif
