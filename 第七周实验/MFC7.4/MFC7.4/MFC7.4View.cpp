
// MFC7.4View.cpp : CMFC74View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7.4.h"
#endif

#include "MFC7.4Doc.h"
#include "MFC7.4View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC74View

IMPLEMENT_DYNCREATE(CMFC74View, CView)

BEGIN_MESSAGE_MAP(CMFC74View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC74View::OnPopout)
END_MESSAGE_MAP()

// CMFC74View 构造/析构

CMFC74View::CMFC74View()
{
	// TODO: 在此处添加构造代码

}

CMFC74View::~CMFC74View()
{
}

BOOL CMFC74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC74View 绘制

void CMFC74View::OnDraw(CDC* /*pDC*/)
{
	CMFC74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC74View 诊断

#ifdef _DEBUG
void CMFC74View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC74Doc* CMFC74View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC74Doc)));
	return (CMFC74Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC74View 消息处理程序


void CMFC74View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int r = dlg.DoModal();
}
