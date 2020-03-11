
// MFC2.3View.cpp : CMFC23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC2.3.h"
#endif

#include "MFC2.3Doc.h"
#include "MFC2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC23View

IMPLEMENT_DYNCREATE(CMFC23View, CView)

BEGIN_MESSAGE_MAP(CMFC23View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC23View ����/����

CMFC23View::CMFC23View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC23View::~CMFC23View()
{
}

BOOL CMFC23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC23View ����

void CMFC23View::OnDraw(CDC* /*pDC*/)
{
	CMFC23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC23View ���

#ifdef _DEBUG
void CMFC23View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC23Doc* CMFC23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC23Doc)));
	return (CMFC23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC23View ��Ϣ�������


void CMFC23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s=_T("�����������");
	CClientDC dc(this);
    dc.TextOutW(100,100,s);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC23View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s1=_T("�������̧��");
	CClientDC dc(this);
    dc.TextOutW(400, 400, s1);
	CView::OnLButtonUp(nFlags, point);
}
