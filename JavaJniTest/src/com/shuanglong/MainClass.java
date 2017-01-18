package com.shuanglong;

import com.shuanglong.jni.MathToolTest;
import com.shuanglong.jni.MethodForCpp;
import com.shuanglong.jni.StringTest;

public class MainClass
{
	static
	{
		System.loadLibrary("libs/JniExample");
	}
	
	public static void main(String[] args)
	{
		System.out.println("=========================== Java JNI Test ===========================");
		
		StringTest.native_sayHello();
		String retString = StringTest.native_transData("TransDataTesting");
		System.out.println("Return from JNI: "+retString);
		System.out.println("Return from JNI: "+StringTest.native_getName());
		
		float[] floatToBeTrans = {0.1f, 0.01f, 0.000f, 0.0001f, 0.000001f, 0.0000001f};
		MathToolTest.native_transFloat(floatToBeTrans);
	
		MethodForCpp.native_cppCallJavaTest();
	}
}
