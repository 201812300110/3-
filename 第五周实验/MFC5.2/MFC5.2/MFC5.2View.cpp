
// MFC5.2View.cpp : CMFC52View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC5.2.h"
#endif

#include "MFC5.2Doc.h"
#include "MFC5.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC52View

IMPLEMENT_DYNCREATE(CMFC52View, CView)

BEGIN_MESSAGE_MAP(CMFC52View, CView)
END_MESSAGE_MAP()

// CMFC52View ����/����

CMFC52View::CMFC52View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFC52View::~CMFC52View()
{
}

BOOL CMFC52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC52View ����

void CMFC52View::OnDraw(CDC* pDC)
{
	CMFC52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,m_nWidth,m_nHeight, &MemDC, 0,0,SRCCOPY);
}


// CMFC52View ���

#ifdef _DEBUG
void CMFC52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC52Doc* CMFC52View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC52Doc)));
	return (CMFC52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC52View ��Ϣ�������
