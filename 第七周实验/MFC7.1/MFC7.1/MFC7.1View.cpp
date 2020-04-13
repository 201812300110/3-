
// MFC7.1View.cpp : CMFC71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7.1.h"
#endif

#include "MFC7.1Doc.h"
#include "MFC7.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC71View

IMPLEMENT_DYNCREATE(CMFC71View, CView)

BEGIN_MESSAGE_MAP(CMFC71View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC71View 构造/析构

CMFC71View::CMFC71View()
{
	// TODO: 在此处添加构造代码

}

CMFC71View::~CMFC71View()
{
}

BOOL CMFC71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC71View 绘制

void CMFC71View::OnDraw(CDC* pDC)
{
	CMFC71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	pDC->Rectangle(pDoc->re);

}


// CMFC71View 诊断

#ifdef _DEBUG
void CMFC71View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC71Doc* CMFC71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC71Doc)));
	return (CMFC71Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC71View 消息处理程序


void CMFC71View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC71Doc* pDoc = GetDocument();
	/*pDoc->re.left = point.x;
	pDoc->re.top = point.y;*/
	pDoc->p.x = point.x;
	pDoc->p.y = point.y;
	pDoc->time = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC71View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC71Doc* pDoc = GetDocument();
	/*pDoc->re.right = point.x;
	pDoc->re.bottom = point.y;
	Invalidate();
	pDoc->p1.x = point.x;
	pDoc->p1.y = point.y;*/
	pDoc->time = 0;
	pDoc->a = point.x - 100;
	pDoc->b = point.y - 100;
	pDoc->c = 350 - point.x;
	pDoc->d = 250 - point.y;
	pDoc->re.left = point.x - pDoc->a; pDoc->re.top = point.y - pDoc->b;
	pDoc->re.right = point.x + pDoc->c; pDoc->re.bottom = point.y + pDoc->d;
	//InvalidateRect(pDoc->re);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC71View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC71Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if (point.x >pDoc->re.left&&point.x<pDoc->re.right&&point.y>pDoc->re.top&&point.y<pDoc->re.bottom&&pDoc->time) {
		pDoc->a = pDoc->p.x - 100;
		pDoc->b = pDoc->p.y - 100;
		pDoc->c = 350 - pDoc->p.x;
		pDoc->d = 250 - pDoc->p.y;
		pDoc->re.left = point.x - pDoc->a; pDoc->re.top = point.y - pDoc->b;
		pDoc->re.right = point.x + pDoc->c; pDoc->re.bottom = point.y + pDoc->d;
		//InvalidateRect(pDoc->re);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
