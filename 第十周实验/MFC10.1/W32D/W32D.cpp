// W32D.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W32D.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

// 这是导出变量的一个示例
W32D_API int nW32D=0;

// 这是导出函数的一个示例。
W32D_API int fnW32D(void)
{
    return 42;
}

W32D_API int factorial1(int n)
{
	if (n>40) return 0;
	if (n == 1) return 1;
	else return n*factorial1(n - 1);
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W32D.h
CW32D::CW32D()
{
    return;
}

float FAC1::convert(float deg)
{
	float a = (deg / 180)*(float)M_PI;
	return a;
}
