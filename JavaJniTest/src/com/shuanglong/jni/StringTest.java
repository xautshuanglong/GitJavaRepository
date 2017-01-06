package com.shuanglong.jni;

public class StringTest
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
	
	native public static void native_sayHello();
	native public static String native_transData(String strData);
	native public static String native_getName();
}
