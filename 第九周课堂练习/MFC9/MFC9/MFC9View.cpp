
// MFC9View.cpp : CMFC9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC9.h"
#endif

#include "MFC9Doc.h"
#include "MFC9View.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC9View

IMPLEMENT_DYNCREATE(CMFC9View, CView)

BEGIN_MESSAGE_MAP(CMFC9View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC9View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMFC9View::OnFileSave)
	ON_COMMAND(ID_POPOUT, &CMFC9View::OnPopout)
END_MESSAGE_MAP()

// CMFC9View 构造/析构

CMFC9View::CMFC9View()
{
	// TODO: 在此处添加构造代码

}

CMFC9View::~CMFC9View()
{
}

BOOL CMFC9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC9View 绘制

void CMFC9View::OnDraw(CDC* /*pDC*/)
{
	CMFC9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

}


// CMFC9View 诊断

#ifdef _DEBUG
void CMFC9View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC9Doc* CMFC9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC9Doc)));
	return (CMFC9Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC9View 消息处理程序


void CMFC9View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		CClientDC dc(this);
		while (ifs >> s) {
			dc.TextOutW(10,10,CString(s.c_str()));
		}
		

	}
}


void CMFC9View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK) {
		ofstream ofs(cfd.GetPathName());
		CString s = cfd.GetPathName();
		ofs <<CT2A(s.GetString()) << endl;
	}
}


void CMFC9View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r==IDOK) {

	}
}
