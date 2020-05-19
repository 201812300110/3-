
// MFC13.3View.cpp : CMFC133View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC13.3.h"
#endif

#include "MFC13.3Set.h"
#include "MFC13.3Doc.h"
#include "MFC13.3View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC133View

IMPLEMENT_DYNCREATE(CMFC133View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC133View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC133View::OnBnClickedButtonDelect)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC133View::OnBnClickedButton1Add)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC133View::OnBnClickedButtonRevise)
END_MESSAGE_MAP()

// CMFC133View 构造/析构

CMFC133View::CMFC133View()
	: CRecordView(IDD_MFC133_FORM)
	, s(_T(""))
	, s1(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC133View::~CMFC133View()
{
}

void CMFC133View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
}

BOOL CMFC133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC133View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC133Set;
	CRecordView::OnInitialUpdate();

}


// CMFC133View 诊断

#ifdef _DEBUG
void CMFC133View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC133View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC133Doc* CMFC133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC133Doc)));
	return (CMFC133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC133View 数据库支持
CRecordset* CMFC133View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC133View 消息处理程序


void CMFC133View::OnBnClickedButtonDelect()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
}


void CMFC133View::OnBnClickedButton1Add()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r==IDOK) 
	{
		long ii = dlg.i;
		m_pSet->AddNew();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFC133View::OnBnClickedButtonRevise()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		long ii = dlg.i;
		m_pSet->Edit();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}
