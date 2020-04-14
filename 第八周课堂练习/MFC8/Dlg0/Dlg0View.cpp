
// Dlg0View.cpp : CDlg0View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CDlg0View ����/����

CDlg0View::CDlg0View()
{
	// TODO: �ڴ˴���ӹ������

}

CDlg0View::~CDlg0View()
{
}

BOOL CDlg0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDlg0View ����

void CDlg0View::OnDraw(CDC* /*pDC*/)
{
	CDlg0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDlg0View ���

#ifdef _DEBUG
void CDlg0View::AssertValid() const
{
	CView::AssertValid();
}

void CDlg0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlg0Doc* CDlg0View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlg0Doc)));
	return (CDlg0Doc*)m_pDocument;
}
#endif //_DEBUG


// CDlg0View ��Ϣ�������


void CDlg0View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���������������
	CDlg0Doc* pDoc = GetDocument();
	MyDlg dlg;
	int r = dlg.DoModal(); 
	dlg.b = pDoc->filename;
	UpdateData(false);
	if (r == IDOK) {

	}
}
