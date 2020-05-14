
// MFC12.1View.cpp : CMFC121View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC12.1.h"
#endif

#include "MFC12.1Set.h"
#include "MFC12.1Doc.h"
#include "MFC12.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC121View

IMPLEMENT_DYNCREATE(CMFC121View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC121View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC121View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC121View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC121View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC121View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC121View 构造/析构

CMFC121View::CMFC121View()
	: CRecordView(IDD_MFC121_FORM)
	, a(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("E:\\照片\\");
	
}

CMFC121View::~CMFC121View()
{
}

void CMFC121View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC121View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC121Set;
	CRecordView::OnInitialUpdate();

}


// CMFC121View 诊断

#ifdef _DEBUG
void CMFC121View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC121View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC121Doc* CMFC121View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC121Doc)));
	return (CMFC121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC121View 数据库支持
CRecordset* CMFC121View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC121View 消息处理程序


void CMFC121View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
}


void CMFC121View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	UpdateData(false);
}


void CMFC121View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveLast();
	}
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	UpdateData(false);
}


void CMFC121View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename); 
	InvalidateRect(&picRect);
	UpdateData(false);
}

void CMFC121View::draw_pic(CString file)
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
		sx =(rect.Width() - w) / 2;
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

void CMFC121View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint().
	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}
