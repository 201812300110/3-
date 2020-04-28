
// MFC9.1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFC91Dlg 对话框
class CMFC91Dlg : public CDialogEx
{
// 构造
public:
	CMFC91Dlg(CWnd* pParent = NULL);	// 标准构造函数
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC91_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	CListBox Lbox;
	CString a;
	int n;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
