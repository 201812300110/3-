
// MFC5View.cpp : CMFC5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC5.h"
#endif

#include "MFC5Doc.h"
#include "MFC5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5View

IMPLEMENT_DYNCREATE(CMFC5View, CView)

BEGIN_MESSAGE_MAP(CMFC5View, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_SHOWCIRCLE, &CMFC5View::OnShowcircle)
END_MESSAGE_MAP()

// CMFC5View ����/����

CMFC5View::CMFC5View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC5View::~CMFC5View()
{
}

BOOL CMFC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC5View ����

void CMFC5View::OnDraw(CDC* pDC)
{
	CMFC5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	pDC->Ellipse(pDoc->cr1);
}


// CMFC5View ���

#ifdef _DEBUG
void CMFC5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5Doc* CMFC5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5Doc)));
	return (CMFC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5View ��Ϣ�������





void CMFC5View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC5Doc* pDoc = GetDocument();
	if (pDoc->cr1.left>0&& pDoc->cr1.top>0) {
		pDoc->cr1.left -= 1;
		pDoc->cr1.top -= 1;
		pDoc->cr1.right += 1;
		pDoc->cr1.bottom += 1;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}


void CMFC5View::OnShowcircle()
{
	// TODO: �ڴ���������������
	CMFC5Doc* pDoc = GetDocument();
	CRect cr;
	this->GetClientRect(&cr);
	pDoc->cr1.left = cr.right / 2;
	pDoc->cr1.top = cr.bottom / 2;
	pDoc->cr1.right = cr.right / 2;
	pDoc->cr1.bottom = cr.bottom / 2;
	if (pDoc->set) {
		SetTimer(0, 100, NULL);
		pDoc->set = false;
	}
}
