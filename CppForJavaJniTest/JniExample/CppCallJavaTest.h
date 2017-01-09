#pragma once

#include <jni.h>

extern void JNICALL Native_CppCallJavaTest(JNIEnv *env, jclass cls);
extern void JNICALL CallStaticMethod(JNIEnv *env);
extern void JNICALL CallInstanceMethod(JNIEnv *env);
