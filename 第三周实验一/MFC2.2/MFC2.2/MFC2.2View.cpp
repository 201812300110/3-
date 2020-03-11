
// MFC2.2View.cpp : CMFC22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2.2.h"
#endif

#include "MFC2.2Doc.h"
#include "MFC2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC22View

IMPLEMENT_DYNCREATE(CMFC22View, CView)

BEGIN_MESSAGE_MAP(CMFC22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC22View 构造/析构

CMFC22View::CMFC22View()
{
	// TODO: 在此处添加构造代码

}

CMFC22View::~CMFC22View()
{
}

BOOL CMFC22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC22View 绘制

void CMFC22View::OnDraw(CDC* pDC)
{
	CMFC22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));

}


// CMFC22View 诊断

#ifdef _DEBUG
void CMFC22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC22Doc* CMFC22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC22Doc)));
	return (CMFC22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC22View 消息处理程序


void CMFC22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int a = rand() % 50 + 5;
	int b = rand() % 100 + 1;
	CClientDC dc(this);
	CRect cr(point.x-a, point.y - b, point.x +a, point.y+b);
	ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
