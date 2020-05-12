
// MFC11.1View.cpp : CMFC111View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFC111View 构造/析构

CMFC111View::CMFC111View()
	: CRecordView(IDD_MFC111_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	//GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
}

CMFC111View::~CMFC111View()
{
}

void CMFC111View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
}

BOOL CMFC111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC111View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC111Set;
	CRecordView::OnInitialUpdate();
	
}


// CMFC111View 诊断

#ifdef _DEBUG
void CMFC111View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC111View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC111Doc* CMFC111View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC111Doc)));
	return (CMFC111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC111View 数据库支持
CRecordset* CMFC111View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC111View 消息处理程序


void CMFC111View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
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
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	UpdateData(false);
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
    InvalidateRect(&picRect);
}


void CMFC111View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	UpdateData(false);
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	InvalidateRect(&picRect);
}
