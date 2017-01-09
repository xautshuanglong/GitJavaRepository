#include "StringTest.h"

#include <iostream>

void JNICALL Native_SayHello(JNIEnv *env, jclass cls)
{
	std::cout << "JNI: Hello,world!" << std::endl;
}

jstring JNICALL Native_TransData(JNIEnv *env, jclass cls, jstring strData)
{
	std::cout << "Inside JNI Native_TransData" << std::endl;
	jstring retString = env->NewStringUTF("ShuangLongTransData");
	
	const char *pStringData = env->GetStringUTFChars(strData, 0);
	std::cout << "strData = " << pStringData << std::endl;
	env->ReleaseStringUTFChars(strData, pStringData);

	return retString;
}

jstring JNICALL Native_GetName(JNIEnv *env, jclass cls)
{
	std::cout << "Inside JNI Native_GetName" << std::endl;
	jstring retString = env->NewStringUTF("ShuanglongJNI");

	jfloatArray fcTest = env->NewFloatArray(1000000);
	env->DeleteLocalRef(fcTest);

	return retString;
}
