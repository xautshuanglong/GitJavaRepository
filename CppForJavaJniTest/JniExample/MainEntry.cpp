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

//	Java����		��������			����
//	boolean		jboolean		C/C++8λ����
//	byte		jbyte			C/C++�����ŵ�8λ����
//	char		jchar			C/C++�޷��ŵ�16λ����
//	short		jshort			C/C++�����ŵ�16λ����
//	int			jint			C/C++�����ŵ�32λ����
//	long		jlong			C/C++�����ŵ�64λ����e
//	float		jfloat			C/C++32λ������
//	double		jdouble			C/C++64λ������
//	Object		jobject			�κ�Java���󣬻���û�ж�Ӧjava���͵Ķ���
//	Class		jclass			Class����
//	String		jstring			�ַ�������
//	Object[]	jobjectArray	�κζ��������
//	boolean[]	jbooleanArray	����������
//	byte[]		jbyteArray		����������
//	char[]		jcharArray		�ַ�������
//	short[]		jshortArray		����������
//	int[]		jintArray		��������
//	long[]		jlongArray		����������
//	float[]		jfloatArray		����������
//	double[]	jdoubleArray	˫����������


//			����					Java��������		��������
//	GetBooleanArrayElements		jbooleanArray	jboolean
//	GetByteArrayElements		jbyteArray		jbyte
//	GetCharArrayElements		jcharArray		jchar
//	GetShortArrayElements		jshortArray		jshort
//	GetIntArrayElements			jintArray		jint
//	GetLongArrayElements		jlongArray		jlong
//	GetFloatArrayElements		jfloatArray		jfloat
//	GetDoubleArrayElements		jdoubleArray	jdouble

//		����						����
//	GetFieldID			�õ�һ��ʵ�������ID
//	GetStaticFieldID	�õ�һ����̬�����ID
//	GetMethodID			�õ�һ��ʵ���ķ�����ID
//	GetStaticMethodID	�õ�һ����̬������ID

//	Java ����		����
//	boolean			Z
//	byte			B
//	char			C
//	short			S
//	int				I
//	long			L
//	float			F
//	double			D
//	void			V
//	objects����		Lfully-qualified-class-name;	L����
//	Arrays����		[array-type						[��������
//	methods����		(argument-types)return-type		(��������)��������
