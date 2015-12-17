#include <node.h>
#include <nan.h>
#include <secp256k1.h>

#include "secretkey.h"
#include "publickey.h"
#include "signature.h"
#include "sign.h"
#include "verify.h"
#include "recover.h"
#include "ecdh.h"


secp256k1_context* secp256k1ctx;

NAN_MODULE_INIT(Init) {
  secp256k1ctx = secp256k1_context_create(
    SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

  // secret key
  Nan::Export(target, "secretKeyVerify", secretKeyVerify);
  Nan::Export(target, "secretKeyExport", secretKeyExport);
  Nan::Export(target, "secretKeyImport", secretKeyImport);
  Nan::Export(target, "secretKeyTweakAdd", secretKeyTweakAdd);
  Nan::Export(target, "secretKeyTweakMul", secretKeyTweakMul);

  // public key
  Nan::Export(target, "publicKeyCreate", publicKeyCreate);
  Nan::Export(target, "publicKeyConvert", publicKeyConvert);
  Nan::Export(target, "publicKeyVerify", publicKeyVerify);
  Nan::Export(target, "publicKeyTweakAdd", publicKeyTweakAdd);
  Nan::Export(target, "publicKeyTweakMul", publicKeyTweakMul);
  Nan::Export(target, "publicKeyCombine", publicKeyCombine);

  // signature
  Nan::Export(target, "signatureNormalize", signatureNormalize);
  Nan::Export(target, "signatureExport", signatureExport);
  Nan::Export(target, "signatureImport", signatureImport);

  // sign
  Nan::Export(target, "sign", sign);

  // verify
  Nan::Export(target, "verify", verify);

  // recover
  Nan::Export(target, "recover", recover);

  // ecdh
  Nan::Export(target, "ecdh", ecdh);
}

NODE_MODULE(secp256k1, Init)
