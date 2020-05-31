
// MFC14View.cpp : CMFC14View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14.h"
#endif

#include "MFC14Set.h"
#include "MFC14Doc.h"
#include "MFC14View.h"
#include "MyDlg.h"
#include "MyDlg2.h"
#include "MyDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC14View

IMPLEMENT_DYNCREATE(CMFC14View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC14View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMFC14View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC14View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC14View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC14View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC14View::OnBnClickedButton1)
	ON_COMMAND(ID_sort, &CMFC14View::Onsort)
	ON_COMMAND(ID_inquire, &CMFC14View::Oninquire)
	ON_COMMAND(ID_add, &CMFC14View::Onadd)
	ON_COMMAND(ID_delect, &CMFC14View::Ondelect)
	ON_COMMAND(ID_alter, &CMFC14View::Onalter)
	ON_COMMAND(ID_recordset, &CMFC14View::Onrecordset)
END_MESSAGE_MAP()

// CMFC14View 构造/析构

CMFC14View::CMFC14View()
	: CRecordView(IDD_MFC14_FORM)
	, ID(0)
	, number(0)
	, name(_T(""))
	, age(0)
	, address(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("E:\\照片\\");

}

CMFC14View::~CMFC14View()
{
}

void CMFC14View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_11);
}

BOOL CMFC14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC14View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC14Set;
	CRecordView::OnInitialUpdate();

}


// CMFC14View 诊断

#ifdef _DEBUG
void CMFC14View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC14View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC14Doc* CMFC14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC14Doc)));
	return (CMFC14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC14View 数据库支持
CRecordset* CMFC14View::OnGetRecordset()
{
	return m_pSet;
}

void CMFC14View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

// CMFC14View 消息处理程序


void CMFC14View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
}


void CMFC14View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
	UpdateData(false);
}


void CMFC14View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveLast();
	}
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
	UpdateData(false);
}


void CMFC14View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
	UpdateData(false);
}

void CMFC14View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	draw_pic(filename);
}


void CMFC14View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	dlg.str = filename;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
	}
}


void CMFC14View::Onsort()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strSort = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}

}


void CMFC14View::Oninquire()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strFilter = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}
	
}


void CMFC14View::Onadd()
{
	// TODO: 在此添加命令处理程序代码
}


void CMFC14View::Ondelect()
{
	// TODO: 在此添加命令处理程序代码
}


void CMFC14View::Onalter()
{
	// TODO: 在此添加命令处理程序代码
}


void CMFC14View::Onrecordset()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg3 dlg3;
	CString str;int i;
	m_pSet->MoveFirst();
	while (!(m_pSet->IsEOF())) {
		for (i = 1; i < m_pSet->GetODBCFieldCount(); i++) {
			m_pSet->GetFieldValue((short)i, str);
			dlg3.str3 = dlg3.str3 + ' '+' ';
			dlg3.str3 = dlg3.str3 + str;
		}
		m_pSet->MoveNext();
	}
	int r = dlg3.DoModal();
}
