
// MFC5.3View.cpp : CMFC53View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5.3.h"
#endif

#include "MFC5.3Doc.h"
#include "MFC5.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC53View

IMPLEMENT_DYNCREATE(CMFC53View, CView)

BEGIN_MESSAGE_MAP(CMFC53View, CView)
	ON_COMMAND(ID_SHOWLINE, &CMFC53View::OnShowline)
	ON_COMMAND(ID_SHOWROUND, &CMFC53View::OnShowround)
	ON_COMMAND(ID_SHOWELLIPSE, &CMFC53View::OnShowellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC53View 构造/析构

CMFC53View::CMFC53View()
{
	// TODO: 在此处添加构造代码

}

CMFC53View::~CMFC53View()
{
}

BOOL CMFC53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC53View 绘制

void CMFC53View::OnDraw(CDC* pDC)
{
	CMFC53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->MoveTo(pDoc->p2);
	pDC->LineTo(pDoc->p3);
	pDC->Rectangle(pDoc->cr1);
	pDC->Ellipse(pDoc->cr2);
}


// CMFC53View 诊断

#ifdef _DEBUG
void CMFC53View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC53Doc* CMFC53View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC53Doc)));
	return (CMFC53Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC53View 消息处理程序


void CMFC53View::OnShowline()
{
	// TODO: 在此添加命令处理程序代码
	CMFC53Doc* pDoc = GetDocument();
	pDoc->a = 1;
	
}


void CMFC53View::OnShowround()
{
	// TODO: 在此添加命令处理程序代码
	CMFC53Doc* pDoc = GetDocument();
	pDoc->b = 1;
	
}


void CMFC53View::OnShowellipse()
{
	// TODO: 在此添加命令处理程序代码
	CMFC53Doc* pDoc = GetDocument();
	pDoc->c = 1;
}


void CMFC53View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC53Doc* pDoc = GetDocument();
	pDoc->p.x = point.x;
	pDoc->p.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC53View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC53Doc* pDoc = GetDocument();
	pDoc->p1.x = point.x;
	pDoc->p1.y = point.y;
	int temp = pDoc->p.x - pDoc->p1.x;
	int temp1 = pDoc->p.y - pDoc->p1.y;
	if (temp != 0 && temp1 != 0 && pDoc->a == 1) {
		pDoc->p2.x = pDoc->p.x; pDoc->p2.y = pDoc->p.y;
		pDoc->p3.x = pDoc->p1.x; pDoc->p3.y = pDoc->p1.y;
		Invalidate();
	}
	if (temp!=0&&temp1!=0&& pDoc->b == 1) {
		pDoc->cr1.left = pDoc->p.x; pDoc->cr1.top = pDoc->p.y;
		pDoc->cr1.right = pDoc->p1.x; pDoc->cr1.bottom = pDoc->p1.y;
		Invalidate();
	}
	if (temp != 0 && temp1 != 0 && pDoc->c == 1) {
		pDoc->cr2.left = pDoc->p.x; pDoc->cr2.top = pDoc->p.y;
		pDoc->cr2.right = pDoc->p1.x; pDoc->cr2.bottom = pDoc->p1.y;
		Invalidate();
	}
	CView::OnLButtonUp(nFlags, point);
}
