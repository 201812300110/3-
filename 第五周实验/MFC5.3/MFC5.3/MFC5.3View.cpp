
// MFC5.3View.cpp : CMFC53View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC5.3.h"
#endif

#include "MFC5.3Doc.h"
#include "MFC5.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC53View

IMPLEMENT_DYNCREATE(CMFC53View, CView)

BEGIN_MESSAGE_MAP(CMFC53View, CView)
	ON_COMMAND(ID_SHOWLINE, &CMFC53View::OnShowline)
	ON_COMMAND(ID_SHOWROUND, &CMFC53View::OnShowround)
	ON_COMMAND(ID_SHOWELLIPSE, &CMFC53View::OnShowellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC53View ����/����

CMFC53View::CMFC53View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC53View::~CMFC53View()
{
}

BOOL CMFC53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC53View ����

void CMFC53View::OnDraw(CDC* pDC)
{
	CMFC53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->MoveTo(pDoc->p2);
	pDC->LineTo(pDoc->p3);
	pDC->Rectangle(pDoc->cr1);
	pDC->Ellipse(pDoc->cr2);
}


// CMFC53View ���

#ifdef _DEBUG
void CMFC53View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC53Doc* CMFC53View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC53Doc)));
	return (CMFC53Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC53View ��Ϣ�������


void CMFC53View::OnShowline()
{
	// TODO: �ڴ���������������
	CMFC53Doc* pDoc = GetDocument();
	pDoc->a = 1;
	
}


void CMFC53View::OnShowround()
{
	// TODO: �ڴ���������������
	CMFC53Doc* pDoc = GetDocument();
	pDoc->b = 1;
	
}


void CMFC53View::OnShowellipse()
{
	// TODO: �ڴ���������������
	CMFC53Doc* pDoc = GetDocument();
	pDoc->c = 1;
}


void CMFC53View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC53Doc* pDoc = GetDocument();
	pDoc->p.x = point.x;
	pDoc->p.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC53View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC53Doc* pDoc = GetDocument();
	pDoc->p1.x = point.x;
	pDoc->p1.y = point.y;
	int temp = pDoc->p.x - pDoc->p1.x;
	int temp1 = pDoc->p.y - pDoc->p1.y;
	if (temp != 0 && temp1 != 0 && pDoc->a == 1) {
		pDoc->p2.x = pDoc->p.x; pDoc->p2.y = pDoc->p.y;
		pDoc->p3.x = pDoc->p1.x; pDoc->p3.y = pDoc->p1.y;
		Invalidate();
	}
	if (temp!=0&&temp1!=0&& pDoc->b == 1) {
		pDoc->cr1.left = pDoc->p.x; pDoc->cr1.top = pDoc->p.y;
		pDoc->cr1.right = pDoc->p1.x; pDoc->cr1.bottom = pDoc->p1.y;
		Invalidate();
	}
	if (temp != 0 && temp1 != 0 && pDoc->c == 1) {
		pDoc->cr2.left = pDoc->p.x; pDoc->cr2.top = pDoc->p.y;
		pDoc->cr2.right = pDoc->p1.x; pDoc->cr2.bottom = pDoc->p1.y;
		Invalidate();
	}
	CView::OnLButtonUp(nFlags, point);
}
