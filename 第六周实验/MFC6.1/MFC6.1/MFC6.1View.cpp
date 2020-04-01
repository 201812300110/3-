
// MFC6.1View.cpp : CMFC61View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC6.1.h"
#endif

#include "MFC6.1Doc.h"
#include "MFC6.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC61View

IMPLEMENT_DYNCREATE(CMFC61View, CView)

BEGIN_MESSAGE_MAP(CMFC61View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
//	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC61View ����/����

CMFC61View::CMFC61View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC61View::~CMFC61View()
{
}

BOOL CMFC61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC61View ����

void CMFC61View::OnDraw(CDC* pDC)
{
	CMFC61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->cr);
	
}


// CMFC61View ���

#ifdef _DEBUG
void CMFC61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC61Doc* CMFC61View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC61Doc)));
	return (CMFC61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC61View ��Ϣ�������


void CMFC61View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC61Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->s1.Format(_T("%c"),nChar);
	if (pDoc->s2.GetLength()<pDoc->cr.right/10) {
		pDoc->s2 = pDoc->s2 + pDoc->s1;
	}
	if (pDoc->p.x>pDoc->cr.left&&pDoc->p.x<pDoc->cr.right&&pDoc->p.y >pDoc->cr.top&&pDoc->p.y<pDoc->cr.bottom&&pDoc->s2.GetLength() < pDoc->cr.right / 10) {
		int a = pDoc->p.x / 10 ;
		pDoc->s2.Insert(a,nChar);
	}
	if (pDoc->s2.GetLength() >= pDoc->cr.right / 10) {
		pDoc->s2.Empty();
		pDoc->i += 20;
	}
	dc.TextOutW(0, pDoc->i,pDoc->s2);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC61Doc* pDoc = GetDocument();
	pDoc->p.x = point.x; pDoc->p.y = point.y;
	pDoc->time = 1;
	CView::OnLButtonDown(nFlags, point);
}



//void CMFC61View::OnRButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CMFC61Doc* pDoc = GetDocument();
//	pDoc->time = 0;
//	CView::OnRButtonDown(nFlags, point);
//}
