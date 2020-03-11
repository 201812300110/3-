
// MFC2.2.h : MFC2.2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC22App:
// 有关此类的实现，请参阅 MFC2.2.cpp
//

class CMFC22App : public CWinApp
{
public:
	CMFC22App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC22App theApp;
