
// MFC4.1View.cpp : CMFC41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.1.h"
#endif

#include "MFC4.1Doc.h"
#include "MFC4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41View

IMPLEMENT_DYNCREATE(CMFC41View, CView)

BEGIN_MESSAGE_MAP(CMFC41View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC41View 构造/析构

CMFC41View::CMFC41View()
{
	// TODO: 在此处添加构造代码

}

CMFC41View::~CMFC41View()
{
}

BOOL CMFC41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41View 绘制

void CMFC41View::OnDraw(CDC* pDC)
{
	CMFC41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s.Format(_T("次数=%d"),pDoc->a);
    int sum = pDoc->b.x - pDoc->c.x;
	CString s1;
	s1.Format(_T("像素：%d"), sum);
	/*CString s2;
	s2.Format(_T("x=%d,y=%d"), pDoc->c.x, pDoc->c.y);*/	
	pDC->TextOutW(20,20,s);
	pDC->TextOutW(50, 50, s1);
}


// CMFC41View 诊断

#ifdef _DEBUG
void CMFC41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41Doc* CMFC41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41Doc)));
	return (CMFC41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41View 消息处理程序



void CMFC41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC41Doc* pDoc = GetDocument();
	if (nFlags&&WM_LBUTTONDOWN) {
        pDoc->a += 1;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFC41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC41Doc* pDoc = GetDocument();
	pDoc->c.x = point.x;
	pDoc->c.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC41Doc* pDoc = GetDocument();
	pDoc->b.x = point.x;
	pDoc->b.y = point.y;
	CView::OnLButtonUp(nFlags, point);
}
