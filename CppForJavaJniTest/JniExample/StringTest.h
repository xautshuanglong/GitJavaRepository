#pragma once

#include <jni.h>

extern void JNICALL Native_SayHello(JNIEnv *env, jclass cls);
extern jstring JNICALL Native_TransData(JNIEnv *env, jclass cls, jstring strData);
extern jstring JNICALL Native_GetName(JNIEnv *env, jclass cls);
