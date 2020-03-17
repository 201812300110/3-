
// MFC4.3View.cpp : CMFC43View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.3.h"
#endif

#include "MFC4.3Doc.h"
#include "MFC4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC43View

IMPLEMENT_DYNCREATE(CMFC43View, CView)

BEGIN_MESSAGE_MAP(CMFC43View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC43View ����/����

CMFC43View::CMFC43View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	CRect a(100, 0, 200, 100);
	cr.Add(a);
	b = 1;
	d = 1;
}

CMFC43View::~CMFC43View()
{
}

BOOL CMFC43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC43View ����

void CMFC43View::OnDraw(CDC* pDC)
{
	CMFC43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set) {
		SetTimer(0,100,NULL);
		set = false;
	}
	pDC->Ellipse(cr[0]);
}


// CMFC43View ���

#ifdef _DEBUG
void CMFC43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC43Doc* CMFC43View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC43Doc)));
	return (CMFC43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC43View ��Ϣ�������


void CMFC43View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC43Doc* pDoc = GetDocument();
	CRect c;
	GetClientRect(&c);
	int n = nIDEvent;
	if (b&&cr[0].bottom <= c.bottom) {
		cr[0].top += 5;
		cr[0].bottom += 5;
		Invalidate();
	}
	if (cr[0].bottom > c.bottom) {
		b = 0;
	}
    if (!b&&cr[0].top>0) {
		cr[0].top -= 10;
		cr[0].bottom -= 10;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}
