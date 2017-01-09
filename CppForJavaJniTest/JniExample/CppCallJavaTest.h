#pragma once

#include <jni.h>

extern void JNICALL Native_CppCallJavaTest(JNIEnv *env, jclass cls);
void JNICALL CallStaticMethod(JNIEnv *env);
void JNICALL CallInstanceMethod(JNIEnv *env);
