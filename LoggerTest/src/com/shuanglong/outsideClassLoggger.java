package com.shuanglong;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class outsideClassLoggger
{

	private static Logger logger = LogManager.getLogger(outsideClassLoggger.class.getName());
	
	public outsideClassLoggger()
	{
		logger.info("constructed");
	}
	
	public void print()
	{
		logger.info("print function");
	}
}
