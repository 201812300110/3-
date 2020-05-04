
// MFC10.1View.cpp : CMFC101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC10.1.h"
#endif

#include "MFC10.1Doc.h"
#include "MFC10.1View.h"
#include "w32.h"
#include "W32D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC101View

IMPLEMENT_DYNCREATE(CMFC101View, CView)

BEGIN_MESSAGE_MAP(CMFC101View, CView)
END_MESSAGE_MAP()

// CMFC101View 构造/析构

CMFC101View::CMFC101View()
{
	// TODO: 在此处添加构造代码

}

CMFC101View::~CMFC101View()
{
}

BOOL CMFC101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC101View 绘制

void CMFC101View::OnDraw(CDC* pDC)
{
	CMFC101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s.Format(_T("%d"),factorial(5));
	pDC->TextOutW(20,20,s);
	CString s1;
	FAC fac;
	s1.Format(_T("%f"),fac.convert(30.0));
	pDC->TextOutW(20, 40, s1);
	CString s2;
	s2.Format(_T("%d"), factorial1(5));
	pDC->TextOutW(20, 60, s2);
	CString s3;
	FAC1 fac1;
	s3.Format(_T("%f"), fac1.convert(30.0));
	pDC->TextOutW(20, 80, s3);

}


// CMFC101View 诊断

#ifdef _DEBUG
void CMFC101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC101Doc* CMFC101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC101Doc)));
	return (CMFC101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC101View 消息处理程序
