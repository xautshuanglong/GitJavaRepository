#include "CppCallJavaTest.h"

#include <iostream>

void Native_CppCallJavaTest(JNIEnv *env, jclass cls)
{
	std::cout << "Inside JNI Native_CppCallJavaTest" << std::endl;

	CallStaticMethod(env);
	CallInstanceMethod(env);
}

void CallStaticMethod(JNIEnv *env)
{
	std::cout << "Inside JNI CallStaticMethod" << std::endl;

	jclass clazz = NULL;
	jmethodID jMethodID = NULL;
	jstring str_arg = NULL;

	clazz = env->FindClass("com/shuanglong/jni/MethodForCpp");
	if (clazz == NULL)
	{
		return;
	}

	jMethodID = env->GetStaticMethodID(clazz, "staticMethodSyaHello", "(Ljava/lang/String;)V");
	if (jMethodID == NULL)
	{
		return;
	}

	str_arg = env->NewStringUTF("JNI: Hello,world!");
	env->CallStaticVoidMethod(clazz, jMethodID, str_arg);

	env->DeleteLocalRef(str_arg);
	env->DeleteLocalRef(clazz);
}

void CallInstanceMethod(JNIEnv *env)
{
	std::cout << "Inside JNI CallInstanceMethod" << std::endl;

	jclass clazz = NULL;
	jobject jInstanceObj = NULL;
	jmethodID jMethodID = NULL;
	jmethodID jConstuctorID = NULL;
	jstring str_arg = NULL;

	clazz = env->FindClass("com/shuanglong/jni/MethodForCpp");
	if (clazz == NULL)
	{
		return;
	}

	jConstuctorID = env->GetMethodID(clazz, "<init>", "()V");
	if (jConstuctorID == NULL)
	{
		return;
	}
	jMethodID = env->GetMethodID(clazz, "instanceMethodPrintString", "(Ljava/lang/String;)V");
	if (jMethodID == NULL)
	{
		return;
	}
	jInstanceObj = env->NewObject(clazz, jConstuctorID);
	if (jInstanceObj == NULL)
	{
		return;
	}
	str_arg = env->NewStringUTF("JNI: print this string!");
	env->CallVoidMethod(jInstanceObj, jMethodID, str_arg);

	env->DeleteLocalRef(jInstanceObj);
	env->DeleteLocalRef(str_arg);
	env->DeleteLocalRef(clazz);
}
