// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC8.22.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, c(0)
	, d(0)
	, s(_T(""))
	, r(0)
	, g(0)
	, y(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT4, d);
	//DDX_Text(pDX, IDC_EDIT5, s);
	DDX_Text(pDX, IDC_EDIT6, r);
	DDX_Text(pDX, IDC_EDIT7, g);
	DDX_Text(pDX, IDC_EDIT8, y);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	//ON_BN_CLICKED(IDC_MFCLINK1, &MyDlg::OnBnClickedMfclink1)
	//ON_BN_CLICKED(IDC_MFCLINK2, &MyDlg::OnBnClickedMfclink2)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedMfclink1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg::OnBnClickedMfclink2()
{
	// TODO: 在此添加控件通知处理程序代码
}
