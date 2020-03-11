
// MFC2.4View.cpp : CMFC24View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2.4.h"
#endif

#include "MFC2.4Doc.h"
#include "MFC2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC24View

IMPLEMENT_DYNCREATE(CMFC24View, CView)

BEGIN_MESSAGE_MAP(CMFC24View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC24View 构造/析构

CMFC24View::CMFC24View()
{
	// TODO: 在此处添加构造代码

}

CMFC24View::~CMFC24View()
{
}

BOOL CMFC24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC24View 绘制

void CMFC24View::OnDraw(CDC* pDC)
{
	CMFC24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	

	
}


// CMFC24View 诊断

#ifdef _DEBUG
void CMFC24View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC24Doc* CMFC24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC24Doc)));
	return (CMFC24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC24View 消息处理程序


void CMFC24View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CClientDC dc(this);
	CString s;
	s.Format(_T("A+B=%d"), pDoc->count);
	dc.TextOutW(500,500,s);
}
