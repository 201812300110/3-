
// MFC7.4View.cpp : CMFC74View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC74View ����/����

CMFC74View::CMFC74View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC74View::~CMFC74View()
{
}

BOOL CMFC74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC74View ����

void CMFC74View::OnDraw(CDC* /*pDC*/)
{
	CMFC74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC74View ���

#ifdef _DEBUG
void CMFC74View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC74Doc* CMFC74View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC74Doc)));
	return (CMFC74Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC74View ��Ϣ�������


void CMFC74View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg0 dlg;
	int r = dlg.DoModal();
}
