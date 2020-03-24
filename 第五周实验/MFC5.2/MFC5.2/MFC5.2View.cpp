
// MFC5.2View.cpp : CMFC52View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5.2.h"
#endif

#include "MFC5.2Doc.h"
#include "MFC5.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC52View

IMPLEMENT_DYNCREATE(CMFC52View, CView)

BEGIN_MESSAGE_MAP(CMFC52View, CView)
END_MESSAGE_MAP()

// CMFC52View 构造/析构

CMFC52View::CMFC52View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFC52View::~CMFC52View()
{
}

BOOL CMFC52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC52View 绘制

void CMFC52View::OnDraw(CDC* pDC)
{
	CMFC52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,m_nWidth,m_nHeight, &MemDC, 0,0,SRCCOPY);
}


// CMFC52View 诊断

#ifdef _DEBUG
void CMFC52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC52Doc* CMFC52View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC52Doc)));
	return (CMFC52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC52View 消息处理程序
