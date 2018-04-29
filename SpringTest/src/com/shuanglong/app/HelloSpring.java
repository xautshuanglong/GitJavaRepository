package com.shuanglong.app;

public class HelloSpring
{
	private String message;
	
	public HelloSpring()
	{
		// TODO Auto-generated constructor stub
	}
	
	public void setMessage(String msg)
	{
		this.message = msg;
	}
	
	public String getMessage()
	{
		return message;
	}
	
	public void printMessage()
	{
		System.out.println("Hello, Spring");
	}
}
