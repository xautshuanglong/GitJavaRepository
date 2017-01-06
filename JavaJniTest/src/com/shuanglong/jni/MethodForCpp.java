package com.shuanglong.jni;

public class MethodForCpp
{
	public MethodForCpp()
	{
		System.out.println("MethodForCpp::MethodForCpp()");
	}
	
	public void instanceMethodPrintString(String printString)
	{
		System.out.println(printString);
	}
	
	public static void staticMethodSyaHello(String helloString)
	{
		System.out.println(helloString);
	}
	
	native public static void native_cppCallJavaTest();
}
