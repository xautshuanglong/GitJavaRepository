#include "StringTest.h"
#include "MathToolTest.h"
#include "CppCallJavaTest.h"

#include <jni.h>
#include <iostream>

#define NATIVE_STRING_TEST "com/shuanglong/jni/StringTest"
#define NATIVE_MATH_TEST "com/shuanglong/jni/MathToolTest"
#define NATIVE_CALLJAVA_TEST "com/shuanglong/jni/MethodForCpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved);
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved);

static JNINativeMethod gNativeStringTestMethods[] = {
	{ "native_sayHello","()V", reinterpret_cast<void *>(Native_SayHello) },
	{ "native_transData","(Ljava/lang/String;)Ljava/lang/String;", reinterpret_cast<void *>(Native_TransData) },
	{ "native_getName","()Ljava/lang/String;", reinterpret_cast<void *>(Native_GetName) }
};

static JNINativeMethod gNativeMathTestMethods[] = {
	{ "native_transFloat","([F)[F", reinterpret_cast<void *>(Native_TransFloat) }
};

static JNINativeMethod gNativeCallJavaTestMethods[] = {
	{ "native_cppCallJavaTest","()V", reinterpret_cast<void *>(Native_CppCallJavaTest) }
};

static const jint gStringTestMethodsCount = sizeof(gNativeStringTestMethods) / sizeof(JNINativeMethod);
static const jint gMathTestMethodsCount = sizeof(gNativeMathTestMethods) / sizeof(JNINativeMethod);
static const jint gCallJavaTestMethodsCount = sizeof(gNativeCallJavaTestMethods) / sizeof(JNINativeMethod);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
	JNIEnv *env;
	jclass cls;
	if (vm->GetEnv(reinterpret_cast<void **>(&env),JNI_VERSION_1_8) != JNI_OK)
	{
		return -1;
	}
	cls = env->FindClass(NATIVE_STRING_TEST);
	env->RegisterNatives(cls, gNativeStringTestMethods, gStringTestMethodsCount);
	env->DeleteLocalRef(cls);

	cls = env->FindClass(NATIVE_MATH_TEST);
	env->RegisterNatives(cls, gNativeMathTestMethods, gMathTestMethodsCount);
	env->DeleteLocalRef(cls);

	cls = env->FindClass(NATIVE_CALLJAVA_TEST);
	env->RegisterNatives(cls, gNativeCallJavaTestMethods, gCallJavaTestMethodsCount);
	env->DeleteLocalRef(cls);

	return JNI_VERSION_1_8;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
	std::cout << "Inside JNI_OnUnload" << std::endl;
}

//	Java类型		本地类型			描述
//	boolean		jboolean		C/C++8位整型
//	byte		jbyte			C/C++带符号的8位整型
//	char		jchar			C/C++无符号的16位整型
//	short		jshort			C/C++带符号的16位整型
//	int			jint			C/C++带符号的32位整型
//	long		jlong			C/C++带符号的64位整型e
//	float		jfloat			C/C++32位浮点型
//	double		jdouble			C/C++64位浮点型
//	Object		jobject			任何Java对象，或者没有对应java类型的对象
//	Class		jclass			Class对象
//	String		jstring			字符串对象
//	Object[]	jobjectArray	任何对象的数组
//	boolean[]	jbooleanArray	布尔型数组
//	byte[]		jbyteArray		比特型数组
//	char[]		jcharArray		字符型数组
//	short[]		jshortArray		短整型数组
//	int[]		jintArray		整型数组
//	long[]		jlongArray		长整型数组
//	float[]		jfloatArray		浮点型数组
//	double[]	jdoubleArray	双浮点型数组


//			函数					Java数组类型		本地类型
//	GetBooleanArrayElements		jbooleanArray	jboolean
//	GetByteArrayElements		jbyteArray		jbyte
//	GetCharArrayElements		jcharArray		jchar
//	GetShortArrayElements		jshortArray		jshort
//	GetIntArrayElements			jintArray		jint
//	GetLongArrayElements		jlongArray		jlong
//	GetFloatArrayElements		jfloatArray		jfloat
//	GetDoubleArrayElements		jdoubleArray	jdouble

//		函数						描述
//	GetFieldID			得到一个实例的域的ID
//	GetStaticFieldID	得到一个静态的域的ID
//	GetMethodID			得到一个实例的方法的ID
//	GetStaticMethodID	得到一个静态方法的ID

//	Java 类型		符号
//	boolean			Z
//	byte			B
//	char			C
//	short			S
//	int				I
//	long			L
//	float			F
//	double			D
//	void			V
//	objects对象		Lfully-qualified-class-name;	L类名
//	Arrays数组		[array-type						[数组类型
//	methods方法		(argument-types)return-type		(参数类型)返回类型
