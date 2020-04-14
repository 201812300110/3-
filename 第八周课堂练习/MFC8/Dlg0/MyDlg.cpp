// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Dlg0.h"
#include "MyDlg.h"
#include "afxdialogex.h"


#include "Dlg0Doc.h"
#include "Dlg0View.h"


IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)

	, b(_T(""))
{
	
}

MyDlg::~MyDlg()
{
	
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	
	DDX_Text(pDX, IDC_EDIT3, b);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &MyDlg::OnLbnSelchangeList1)
	
	ON_EN_CHANGE(IDC_EDIT3, &MyDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// MyDlg 消息处理程序



BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		s = cfd.GetPathName();
	}
	Lbox.AddString(s);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MyDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	b = s;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void MyDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
	// TODO:  在此添加控件通知处理程序代码
}
