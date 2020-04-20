
// MFC8.22View.cpp : CMFC822View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC8.22.h"
#endif

#include "MFC8.22Doc.h"
#include "MFC8.22View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC822View

IMPLEMENT_DYNCREATE(CMFC822View, CView)

BEGIN_MESSAGE_MAP(CMFC822View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC822View::OnPopout)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC822View 构造/析构

CMFC822View::CMFC822View()
{
	// TODO: 在此处添加构造代码

}

CMFC822View::~CMFC822View()
{
}

BOOL CMFC822View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC822View 绘制

void CMFC822View::OnDraw(CDC* pDC)
{
	CMFC822Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC822View 诊断

#ifdef _DEBUG
void CMFC822View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC822View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC822Doc* CMFC822View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC822Doc)));
	return (CMFC822Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC822View 消息处理程序


void CMFC822View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	CMFC822Doc* pDoc = GetDocument();
	CClientDC dc(this);
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		pDoc->re.left = dlg.a;
		pDoc->re.top  = dlg.b;
		pDoc->re.right  = dlg.c;
		pDoc->re.bottom  = dlg.d;
		int color1 = RGB(dlg.r,dlg.g,dlg.y);
		CBrush brush(color1);
		CBrush*oldbrush = dc.SelectObject(&brush);
		dc.Ellipse(pDoc->re);
		dc.SelectObject(oldbrush);
	}
}


void CMFC822View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC822Doc* pDoc = GetDocument();
	CClientDC dc(this);
	long long a1,b1,c1,d1,sum,sum1;
	a1 = (pDoc->re.left + pDoc->re.right) / 2;
	b1 = (pDoc->re.top + pDoc->re.bottom) / 2;
	c1 = pDoc->re.Width()*pDoc->re.Width() / 4;
	d1 = pDoc->re.Height()*pDoc->re.Height() / 4;
	sum = (point.x - a1)*(point.x - a1)*d1 + (point.y - b1)*(point.y - b1)*c1;
	sum1 = c1*d1;
	if (sum<sum1) {
		int red = 0, green = 0, blue = 0;
		int color = RGB(red, green, blue);
		CPen newPen(PS_DASH,1,color);
		CPen*oldPen = dc.SelectObject(&newPen);
		dc.MoveTo(pDoc->re.left, pDoc->re.top);
		dc.LineTo(pDoc->re.left+ pDoc->re.Width(), pDoc->re.top);
		dc.MoveTo(pDoc->re.left + pDoc->re.Width(), pDoc->re.top);
		dc.LineTo(pDoc->re.left + pDoc->re.Width(), pDoc->re.top+ pDoc->re.Height());
		dc.MoveTo(pDoc->re.left + pDoc->re.Width(), pDoc->re.top+ pDoc->re.Height());
		dc.LineTo(pDoc->re.left, pDoc->re.top + pDoc->re.Height());
		dc.MoveTo(pDoc->re.left, pDoc->re.top + pDoc->re.Height());
		dc.LineTo(pDoc->re.left, pDoc->re.top);
		dc.SelectObject(oldPen);
	}
	CView::OnLButtonDown(nFlags, point);
}
