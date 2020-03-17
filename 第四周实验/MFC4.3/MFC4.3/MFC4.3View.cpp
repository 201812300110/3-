
// MFC4.3View.cpp : CMFC43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.3.h"
#endif

#include "MFC4.3Doc.h"
#include "MFC4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC43View

IMPLEMENT_DYNCREATE(CMFC43View, CView)

BEGIN_MESSAGE_MAP(CMFC43View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC43View 构造/析构

CMFC43View::CMFC43View()
{
	// TODO: 在此处添加构造代码
	set = true;
	CRect a(100, 0, 200, 100);
	cr.Add(a);
	b = 1;
	d = 1;
}

CMFC43View::~CMFC43View()
{
}

BOOL CMFC43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC43View 绘制

void CMFC43View::OnDraw(CDC* pDC)
{
	CMFC43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set) {
		SetTimer(0,100,NULL);
		set = false;
	}
	pDC->Ellipse(cr[0]);
}


// CMFC43View 诊断

#ifdef _DEBUG
void CMFC43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC43Doc* CMFC43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC43Doc)));
	return (CMFC43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC43View 消息处理程序


void CMFC43View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC43Doc* pDoc = GetDocument();
	CRect c;
	GetClientRect(&c);
	int n = nIDEvent;
	if (b&&cr[0].bottom <= c.bottom) {
		cr[0].top += 5;
		cr[0].bottom += 5;
		Invalidate();
	}
	if (cr[0].bottom > c.bottom) {
		b = 0;
	}
    if (!b&&cr[0].top>0) {
		cr[0].top -= 10;
		cr[0].bottom -= 10;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}
