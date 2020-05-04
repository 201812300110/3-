#include "stdafx.h"
#include "w32.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


int factorial(int n)
{
	if(n>40) return 0;
	if (n == 1) return 1;
	else return n*factorial(n - 1);
}


float FAC::convert(float deg)
{
	float a =(deg/180)*(float)M_PI;
	return a;
}
