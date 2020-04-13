
// MFC7.3View.cpp : CMFC73View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7.3.h"
#endif

#include "MFC7.3Doc.h"
#include "MFC7.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC73View

IMPLEMENT_DYNCREATE(CMFC73View, CView)

BEGIN_MESSAGE_MAP(CMFC73View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC73View 构造/析构

CMFC73View::CMFC73View()
{
	// TODO: 在此处添加构造代码

}

CMFC73View::~CMFC73View()
{
}

BOOL CMFC73View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC73View 绘制

void CMFC73View::OnDraw(CDC*pDC)
{
	CMFC73Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	GetClientRect(&cr);
	pDoc->re.top = cr.bottom / 2 - 50;
	pDoc->re.bottom = cr.bottom / 2+50;
	pDC->Ellipse(pDoc->re);
	if (pDoc->set) {
		SetTimer(0,100,NULL);
	}
}


// CMFC73View 诊断

#ifdef _DEBUG
void CMFC73View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC73View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC73Doc* CMFC73View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC73Doc)));
	return (CMFC73Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC73View 消息处理程序


void CMFC73View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC73Doc* pDoc = GetDocument();
	pDoc->a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC73View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC73Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	if (pDoc->a&&pDoc->re.right<=cr.right&&!pDoc->b) {
		pDoc->re.left += 5; pDoc->re.right += 5;
		Invalidate();
	}
	if (pDoc->re.right >= cr.right) pDoc->b = 1;
	if (pDoc->a&&pDoc->re.left>=0&&pDoc->b) {
		pDoc->re.left -= 5; pDoc->re.right -= 5;
		Invalidate();
	}
	if (pDoc->re.left <= 0) pDoc->b = 0;
	CView::OnTimer(nIDEvent);
}


void CMFC73View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC73Doc* pDoc = GetDocument();
	pDoc->a = 0;
	CView::OnLButtonDblClk(nFlags, point);
}
