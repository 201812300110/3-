
// MFC4.1View.cpp : CMFC41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.1.h"
#endif

#include "MFC4.1Doc.h"
#include "MFC4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41View

IMPLEMENT_DYNCREATE(CMFC41View, CView)

BEGIN_MESSAGE_MAP(CMFC41View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC41View ����/����

CMFC41View::CMFC41View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC41View::~CMFC41View()
{
}

BOOL CMFC41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC41View ����

void CMFC41View::OnDraw(CDC* pDC)
{
	CMFC41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s.Format(_T("����=%d"),pDoc->a);
    int sum = pDoc->b.x - pDoc->c.x;
	CString s1;
	s1.Format(_T("���أ�%d"), sum);
	/*CString s2;
	s2.Format(_T("x=%d,y=%d"), pDoc->c.x, pDoc->c.y);*/	
	pDC->TextOutW(20,20,s);
	pDC->TextOutW(50, 50, s1);
}


// CMFC41View ���

#ifdef _DEBUG
void CMFC41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41Doc* CMFC41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41Doc)));
	return (CMFC41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41View ��Ϣ�������



void CMFC41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC41Doc* pDoc = GetDocument();
	if (nFlags&&WM_LBUTTONDOWN) {
        pDoc->a += 1;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFC41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC41Doc* pDoc = GetDocument();
	pDoc->c.x = point.x;
	pDoc->c.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC41Doc* pDoc = GetDocument();
	pDoc->b.x = point.x;
	pDoc->b.y = point.y;
	CView::OnLButtonUp(nFlags, point);
}
