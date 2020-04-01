
// MFC6View.cpp : CMFC6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6.h"
#endif

#include "MFC6Doc.h"
#include "MFC6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6View

IMPLEMENT_DYNCREATE(CMFC6View, CView)

BEGIN_MESSAGE_MAP(CMFC6View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC6View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC6View 构造/析构

CMFC6View::CMFC6View()
{
	// TODO: 在此处添加构造代码

}

CMFC6View::~CMFC6View()
{
}

BOOL CMFC6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC6View 绘制

void CMFC6View::OnDraw(CDC* pDC)
{
	CMFC6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// CMFC6View 诊断

#ifdef _DEBUG
void CMFC6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6Doc* CMFC6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6Doc)));
	return (CMFC6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6View 消息处理程序


void CMFC6View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CMFC6Doc* pDoc = GetDocument();
	CRect cr;
	this->GetClientRect(&cr);
	CFileDialog cfd(true);  //建立对象
	int r = cfd.DoModal();  //弹出对话框
	CClientDC dc(this);
    CString filename = cfd.GetPathName();
	/*if (r == IDOK){	
		dc.TextOutW(300, 200, filename);
	}*/
	CImage img;
	img.Load(filename);
	img.Draw(dc.m_hDC, cr.right/2- img.GetWidth()/2, cr.bottom/2- img.GetHeight()/2, img.GetWidth(), img.GetHeight());
}
