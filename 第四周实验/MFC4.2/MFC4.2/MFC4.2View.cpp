
// MFC4.2View.cpp : CMFC42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.2.h"
#endif

#include "MFC4.2Doc.h"
#include "MFC4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42View

IMPLEMENT_DYNCREATE(CMFC42View, CView)

BEGIN_MESSAGE_MAP(CMFC42View, CView)
	ON_WM_KEYDOWN()
//	ON_WM_CHAR()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC42View ����/����

CMFC42View::CMFC42View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC42View::~CMFC42View()
{
}

BOOL CMFC42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42View ����

void CMFC42View::OnDraw(CDC* pDC)
{
	CMFC42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->a);
}


// CMFC42View ���

#ifdef _DEBUG
void CMFC42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42Doc* CMFC42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42Doc)));
	return (CMFC42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42View ��Ϣ�������


void CMFC42View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC42Doc* pDoc = GetDocument();
	CRect b;
	GetClientRect(&b);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->a.left>0) {
			pDoc->a.left -= 5;
			pDoc->a.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->a.right<(b.right-b.left)) {
			pDoc->a.left += 5;
			pDoc->a.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->a.top>0) {
			pDoc->a.top -= 5;
			pDoc->a.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->a.bottom<(b.bottom - b.top)) {
			pDoc->a.top += 5;
			pDoc->a.bottom += 5;
		}
		break;
	case VK_HOME:
		if (pDoc->a.left>0&&pDoc->a.top>0) {
			pDoc->a.left -= 5;
			pDoc->a.top -= 5;
		}
		break;
	case VK_END:
		if (pDoc->a.left<b.right&&pDoc->a.top<b.bottom) {
			pDoc->a.left += 5;
			pDoc->a.top += 5;
		}
		break;
	}
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}





void CMFC42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC42Doc* pDoc = GetDocument();
	pDoc->a.left = 550; 
	pDoc->a.top = 150;
	pDoc->a.right = 850; 
	pDoc->a.bottom = 400;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
