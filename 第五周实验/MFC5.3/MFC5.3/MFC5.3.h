
// MFC5.3.h : MFC5.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC53App:
// �йش����ʵ�֣������ MFC5.3.cpp
//

class CMFC53App : public CWinApp
{
public:
	CMFC53App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC53App theApp;
