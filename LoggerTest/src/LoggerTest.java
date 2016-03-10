import org.apache.logging.log4j.Level;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import com.shuanglong.outsideClassLoggger;

public class LoggerTest
{
	private static Logger logger = LogManager.getLogger(LoggerTest.class.getName());
    public static void main(String[] args)
    {
        logger.entry("entry");
        logger.trace("trace");
        logger.info("info");
        logger.debug("debug");
        logger.warn("warn");
        logger.fatal("fatal");
        
        logger.log(Level.DEBUG, "log SpecifyLevel");
        logger.error("error");
        logger.exit();
        
        outsideClassLoggger out = new outsideClassLoggger();
        out.print();
    }
}
