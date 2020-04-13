
// MFC7.3View.cpp : CMFC73View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC7.3.h"
#endif

#include "MFC7.3Doc.h"
#include "MFC7.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC73View

IMPLEMENT_DYNCREATE(CMFC73View, CView)

BEGIN_MESSAGE_MAP(CMFC73View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC73View ����/����

CMFC73View::CMFC73View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC73View::~CMFC73View()
{
}

BOOL CMFC73View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC73View ����

void CMFC73View::OnDraw(CDC*pDC)
{
	CMFC73Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr;
	GetClientRect(&cr);
	pDoc->re.top = cr.bottom / 2 - 50;
	pDoc->re.bottom = cr.bottom / 2+50;
	pDC->Ellipse(pDoc->re);
	if (pDoc->set) {
		SetTimer(0,100,NULL);
	}
}


// CMFC73View ���

#ifdef _DEBUG
void CMFC73View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC73View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC73Doc* CMFC73View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC73Doc)));
	return (CMFC73Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC73View ��Ϣ�������


void CMFC73View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC73Doc* pDoc = GetDocument();
	pDoc->a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC73View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC73Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	if (pDoc->a&&pDoc->re.right<=cr.right&&!pDoc->b) {
		pDoc->re.left += 5; pDoc->re.right += 5;
		Invalidate();
	}
	if (pDoc->re.right >= cr.right) pDoc->b = 1;
	if (pDoc->a&&pDoc->re.left>=0&&pDoc->b) {
		pDoc->re.left -= 5; pDoc->re.right -= 5;
		Invalidate();
	}
	if (pDoc->re.left <= 0) pDoc->b = 0;
	CView::OnTimer(nIDEvent);
}


void CMFC73View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC73Doc* pDoc = GetDocument();
	pDoc->a = 0;
	CView::OnLButtonDblClk(nFlags, point);
}
