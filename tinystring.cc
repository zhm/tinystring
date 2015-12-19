#include "tinystring.h"

Nan::Persistent<v8::Function> TinyString::constructor;

TinyString::TinyString(std::string value) {
  value_ << value;
}

TinyString::~TinyString() {
}

void TinyString::Init(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;

  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("TinyString").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  Nan::SetPrototypeMethod(tpl, "value", GetValue);
  Nan::SetPrototypeMethod(tpl, "append", Append);

  constructor.Reset(tpl->GetFunction());

  exports->Set(Nan::New("TinyString").ToLocalChecked(), tpl->GetFunction());
}

void TinyString::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.IsConstructCall()) {
    std::string value = info[0]->IsUndefined() ? "" : *Nan::Utf8String(info[0]);
    TinyString *obj = new TinyString(value);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { info[0] };
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void TinyString::GetValue(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  TinyString* obj = ObjectWrap::Unwrap<TinyString>(info.Holder());
  info.GetReturnValue().Set(Nan::New(obj->value_.str()).ToLocalChecked());
}

void TinyString::Append(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  TinyString *obj = ObjectWrap::Unwrap<TinyString>(info.Holder());

  std::string value = *Nan::Utf8String(info[0]);

  obj->value_ << value;

  info.GetReturnValue().Set(info.This());
}
