
// MFC10.1View.cpp : CMFC101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC10.1.h"
#endif

#include "MFC10.1Doc.h"
#include "MFC10.1View.h"
#include "w32.h"
#include "W32D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC101View

IMPLEMENT_DYNCREATE(CMFC101View, CView)

BEGIN_MESSAGE_MAP(CMFC101View, CView)
END_MESSAGE_MAP()

// CMFC101View ����/����

CMFC101View::CMFC101View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC101View::~CMFC101View()
{
}

BOOL CMFC101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC101View ����

void CMFC101View::OnDraw(CDC* pDC)
{
	CMFC101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s.Format(_T("%d"),factorial(5));
	pDC->TextOutW(20,20,s);
	CString s1;
	FAC fac;
	s1.Format(_T("%f"),fac.convert(30.0));
	pDC->TextOutW(20, 40, s1);
	CString s2;
	s2.Format(_T("%d"), factorial1(5));
	pDC->TextOutW(20, 60, s2);
	CString s3;
	FAC1 fac1;
	s3.Format(_T("%f"), fac1.convert(30.0));
	pDC->TextOutW(20, 80, s3);

}


// CMFC101View ���

#ifdef _DEBUG
void CMFC101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC101Doc* CMFC101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC101Doc)));
	return (CMFC101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC101View ��Ϣ�������
