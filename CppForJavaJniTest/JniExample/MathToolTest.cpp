#include "MathToolTest.h"

#include <iostream>

extern jfloatArray JNICALL Native_TransFloat(jfloatArray floatAarray)
{
	std::cout << "Inside JNI Native_TransFloat" << std::endl;
	jfloatArray retValue = NULL;

	return retValue;
}