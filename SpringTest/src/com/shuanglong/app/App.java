package com.shuanglong.app;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App
{
	public static void main(String[] args)
	{
		@SuppressWarnings("resource")
		ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");
		HelloSpring obj = (HelloSpring) context.getBean("HelloSpring");
		String msg= obj.getMessage();
		System.out.println(msg);
		obj.printMessage();
	}
}
