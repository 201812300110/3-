
// MFC2.2View.cpp : CMFC22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC2.2.h"
#endif

#include "MFC2.2Doc.h"
#include "MFC2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC22View

IMPLEMENT_DYNCREATE(CMFC22View, CView)

BEGIN_MESSAGE_MAP(CMFC22View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC22View ����/����

CMFC22View::CMFC22View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC22View::~CMFC22View()
{
}

BOOL CMFC22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC22View ����

void CMFC22View::OnDraw(CDC* pDC)
{
	CMFC22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));

}


// CMFC22View ���

#ifdef _DEBUG
void CMFC22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC22Doc* CMFC22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC22Doc)));
	return (CMFC22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC22View ��Ϣ�������


void CMFC22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand() % 50 + 5;
	int b = rand() % 100 + 1;
	CClientDC dc(this);
	CRect cr(point.x-a, point.y - b, point.x +a, point.y+b);
	ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
