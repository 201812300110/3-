
// MFC7.2View.cpp : CMFC72View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7.2.h"
#endif

#include "MFC7.2Doc.h"
#include "MFC7.2View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC72View

IMPLEMENT_DYNCREATE(CMFC72View, CView)

BEGIN_MESSAGE_MAP(CMFC72View, CView)
	ON_COMMAND(ID_POPOU, &CMFC72View::OnPopou)
END_MESSAGE_MAP()

// CMFC72View 构造/析构

CMFC72View::CMFC72View()
{
	// TODO: 在此处添加构造代码

}

CMFC72View::~CMFC72View()
{
}

BOOL CMFC72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC72View 绘制

void CMFC72View::OnDraw(CDC* /*pDC*/)
{
	CMFC72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC72View 诊断

#ifdef _DEBUG
void CMFC72View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC72Doc* CMFC72View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC72Doc)));
	return (CMFC72Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC72View 消息处理程序


void CMFC72View::OnPopou()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		
	}
}
