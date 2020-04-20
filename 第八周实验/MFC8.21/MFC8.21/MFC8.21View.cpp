
// MFC8.21View.cpp : CMFC821View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC8.21.h"
#endif

#include "MFC8.21Doc.h"
#include "MFC8.21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC821View

IMPLEMENT_DYNCREATE(CMFC821View, CView)

BEGIN_MESSAGE_MAP(CMFC821View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC821View 构造/析构

CMFC821View::CMFC821View()
{
	// TODO: 在此处添加构造代码

}

CMFC821View::~CMFC821View()
{
}

BOOL CMFC821View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC821View 绘制

void CMFC821View::OnDraw(CDC* pDC)
{
	CMFC821Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->re);


}


// CMFC821View 诊断

#ifdef _DEBUG
void CMFC821View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC821View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC821Doc* CMFC821View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC821Doc)));
	return (CMFC821Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC821View 消息处理程序


void CMFC821View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC821Doc* pDoc = GetDocument();
	pDoc->re.left = point.x;
	pDoc->re.top = point.y;
	pDoc->a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC821View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC821Doc* pDoc = GetDocument();
	if (pDoc->a) {
		pDoc->re.right = point.x;
		pDoc->re.bottom = point.y;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFC821View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC821Doc* pDoc = GetDocument();
	pDoc->re.right = point.x;
	pDoc->re.bottom = point.y;
	pDoc->a = 0;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
