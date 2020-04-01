
// MFC6.1View.cpp : CMFC61View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6.1.h"
#endif

#include "MFC6.1Doc.h"
#include "MFC6.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC61View

IMPLEMENT_DYNCREATE(CMFC61View, CView)

BEGIN_MESSAGE_MAP(CMFC61View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
//	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC61View 构造/析构

CMFC61View::CMFC61View()
{
	// TODO: 在此处添加构造代码

}

CMFC61View::~CMFC61View()
{
}

BOOL CMFC61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC61View 绘制

void CMFC61View::OnDraw(CDC* pDC)
{
	CMFC61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr);
	
}


// CMFC61View 诊断

#ifdef _DEBUG
void CMFC61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC61Doc* CMFC61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC61Doc)));
	return (CMFC61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC61View 消息处理程序


void CMFC61View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC61Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->s1.Format(_T("%c"),nChar);
	if (pDoc->s2.GetLength()<pDoc->cr.right/10) {
		pDoc->s2 = pDoc->s2 + pDoc->s1;
	}
	if (pDoc->p.x>pDoc->cr.left&&pDoc->p.x<pDoc->cr.right&&pDoc->p.y >pDoc->cr.top&&pDoc->p.y<pDoc->cr.bottom&&pDoc->s2.GetLength() < pDoc->cr.right / 10) {
		int a = pDoc->p.x / 10 ;
		pDoc->s2.Insert(a,nChar);
	}
	if (pDoc->s2.GetLength() >= pDoc->cr.right / 10) {
		pDoc->s2.Empty();
		pDoc->i += 20;
	}
	dc.TextOutW(0, pDoc->i,pDoc->s2);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC61Doc* pDoc = GetDocument();
	pDoc->p.x = point.x; pDoc->p.y = point.y;
	pDoc->time = 1;
	CView::OnLButtonDown(nFlags, point);
}



//void CMFC61View::OnRButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CMFC61Doc* pDoc = GetDocument();
//	pDoc->time = 0;
//	CView::OnRButtonDown(nFlags, point);
//}
