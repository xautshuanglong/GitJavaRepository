package com.shuanglong.jni;

public class MathToolTest
{
//	static
//	{
//		String libPath = System.getProperty("java.library.path");
//		String pathArray[] = libPath.split(";");
//		for (String pathItem : pathArray)
//		{
//			System.out.println(pathItem);
//		}
//		
//		System.loadLibrary("libs/JniExample");
//	}

	native public static float[] native_transFloat(float[] floatArray);
}
