
// Dlg0View.cpp : CDlg0View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Dlg0.h"
#endif

#include "Dlg0Doc.h"
#include "Dlg0View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlg0View

IMPLEMENT_DYNCREATE(CDlg0View, CView)

BEGIN_MESSAGE_MAP(CDlg0View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_POPOUT, &CDlg0View::OnPopout)
END_MESSAGE_MAP()

// CDlg0View 构造/析构

CDlg0View::CDlg0View()
{
	// TODO: 在此处添加构造代码

}

CDlg0View::~CDlg0View()
{
}

BOOL CDlg0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDlg0View 绘制

void CDlg0View::OnDraw(CDC* /*pDC*/)
{
	CDlg0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDlg0View 诊断

#ifdef _DEBUG
void CDlg0View::AssertValid() const
{
	CView::AssertValid();
}

void CDlg0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlg0Doc* CDlg0View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlg0Doc)));
	return (CDlg0Doc*)m_pDocument;
}
#endif //_DEBUG


// CDlg0View 消息处理程序


void CDlg0View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*MyDlg *pD = new MyDlg;
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1);*/
	CDlg0Doc* pDoc = GetDocument();
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r==IDOK) {
		pDoc->filename = cfd.GetPathName();
		GetDC()->TextOutW(100,100,pDoc->filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CDlg0View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	CDlg0Doc* pDoc = GetDocument();
	MyDlg dlg;
	int r = dlg.DoModal(); 
	dlg.b = pDoc->filename;
	UpdateData(false);
	if (r == IDOK) {

	}
}
