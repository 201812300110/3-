
// MFC10View.cpp : CMFC10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC10.h"
#endif

#include "MFC10Doc.h"
#include "MFC10View.h"
#include "w32.h"
#include "W32D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC10View

IMPLEMENT_DYNCREATE(CMFC10View, CView)

BEGIN_MESSAGE_MAP(CMFC10View, CView)
END_MESSAGE_MAP()

// CMFC10View 构造/析构

CMFC10View::CMFC10View()
{
	// TODO: 在此处添加构造代码

}

CMFC10View::~CMFC10View()
{
}

BOOL CMFC10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC10View 绘制

void CMFC10View::OnDraw(CDC* pDC)
{
	CMFC10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s = CString(pchar());
	pDC->TextOutW(100,100,s);
	CString ss;
	ss.Format(_T("%d,这是从动态库返回的值。"), GetInt());
	pDC->TextOutW(100, 200, ss);

}


// CMFC10View 诊断

#ifdef _DEBUG
void CMFC10View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC10Doc* CMFC10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC10Doc)));
	return (CMFC10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC10View 消息处理程序
