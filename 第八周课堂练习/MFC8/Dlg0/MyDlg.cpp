// MyDlg.cpp : ʵ���ļ�
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


// MyDlg ��Ϣ�������



BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		s = cfd.GetPathName();
	}
	Lbox.AddString(s);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void MyDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	b = s;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void MyDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
