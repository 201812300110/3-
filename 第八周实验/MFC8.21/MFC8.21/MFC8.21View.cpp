
// MFC8.21View.cpp : CMFC821View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC8.21.h"
#endif

#include "MFC8.21Doc.h"
#include "MFC8.21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC821View

IMPLEMENT_DYNCREATE(CMFC821View, CView)

BEGIN_MESSAGE_MAP(CMFC821View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC821View ����/����

CMFC821View::CMFC821View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC821View::~CMFC821View()
{
}

BOOL CMFC821View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC821View ����

void CMFC821View::OnDraw(CDC* pDC)
{
	CMFC821Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(pDoc->re);


}


// CMFC821View ���

#ifdef _DEBUG
void CMFC821View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC821View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC821Doc* CMFC821View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC821Doc)));
	return (CMFC821Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC821View ��Ϣ�������


void CMFC821View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC821Doc* pDoc = GetDocument();
	pDoc->re.left = point.x;
	pDoc->re.top = point.y;
	pDoc->a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC821View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC821Doc* pDoc = GetDocument();
	if (pDoc->a) {
		pDoc->re.right = point.x;
		pDoc->re.bottom = point.y;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFC821View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC821Doc* pDoc = GetDocument();
	pDoc->re.right = point.x;
	pDoc->re.bottom = point.y;
	pDoc->a = 0;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
