
// MFC2.5View.cpp : CMFC25View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2.5.h"
#endif

#include "MFC2.5Doc.h"
#include "MFC2.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC25View

IMPLEMENT_DYNCREATE(CMFC25View, CView)

BEGIN_MESSAGE_MAP(CMFC25View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC25View 构造/析构

CMFC25View::CMFC25View()
{
	// TODO: 在此处添加构造代码

}

CMFC25View::~CMFC25View()
{
}

BOOL CMFC25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC25View 绘制

void CMFC25View::OnDraw(CDC*pDC)
{
	CMFC25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect A(200-100,200-60,200+100,200+60);
	pDC->Rectangle(A);
	CRect B(600 - 85, 200 - 50, 600 + 85, 200 + 50);
	pDC->Rectangle(B);
	CRect C(1000 - 100, 200 - 50, 1000 + 100, 200 + 50);
	pDC->Rectangle(C);
	
}


// CMFC25View 诊断

#ifdef _DEBUG
void CMFC25View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC25Doc* CMFC25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC25Doc)));
	return (CMFC25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC25View 消息处理程序


void CMFC25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//int a=0,b=0,c=0;
	if (point.x > 100 && point.x < 300 && point.y>140 && point.y < 260) {
		pDoc->a = rand() % 1000;
		CString s1;
		s1.Format(_T("%d"),pDoc->a);
		CClientDC dc(this);
		dc.TextOutW(200,200,s1);
	}
	else if (point.x > 515 && point.x < 685 && point.y>150 && point.y < 250) {
		pDoc->b = rand() % 1000;
		CString s2;
		s2.Format(_T("%d"), pDoc->b);
		CClientDC dc(this);
		dc.TextOutW(600, 200, s2);
	}	
	else if (point.x > 900 && point.x < 1100 && point.y>150 && point.y < 250) {
	    int c = pDoc->a + pDoc->b;
		CString s4;
		s4.Format(_T("%d"), c);
		CClientDC dc(this);
		dc.TextOutW(1000, 200, s4);
	}
    else {
		CString s3=_T("点击无效");
		CClientDC dc(this);
		dc.TextOutW(10, 10, s3);
	}
	

	CView::OnLButtonDown(nFlags, point);
}
