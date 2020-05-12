
// MFC11.1View.cpp : CMFC111View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC11.1.h"
#endif

#include "MFC11.1Set.h"
#include "MFC11.1Doc.h"
#include "MFC11.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC111View

IMPLEMENT_DYNCREATE(CMFC111View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC111View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC111View::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_NEXT, &CMFC111View::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &CMFC111View::OnRecordPrev)
END_MESSAGE_MAP()

// CMFC111View ����/����

CMFC111View::CMFC111View()
	: CRecordView(IDD_MFC111_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	//GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
}

CMFC111View::~CMFC111View()
{
}

void CMFC111View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
}

BOOL CMFC111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC111View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC111Set;
	CRecordView::OnInitialUpdate();
	
}


// CMFC111View ���

#ifdef _DEBUG
void CMFC111View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC111View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC111Doc* CMFC111View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC111Doc)));
	return (CMFC111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC111View ���ݿ�֧��
CRecordset* CMFC111View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC111View ��Ϣ�������


void CMFC111View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	m_pSet->GetFieldValue(short(4), s);
	CImage img;
	img.Load(s);
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
	
}





void CMFC111View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString s;
	m_pSet->GetFieldValue(short(4), s);
	CImage img; img.Load(s);
    picRect.left = 0; picRect.top = 0;
	picRect.right = img.GetWidth(); picRect.bottom = img.GetHeight();
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
}


void CMFC111View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	UpdateData(false);
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
    InvalidateRect(&picRect);
}


void CMFC111View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	UpdateData(false);
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	InvalidateRect(&picRect);
}
