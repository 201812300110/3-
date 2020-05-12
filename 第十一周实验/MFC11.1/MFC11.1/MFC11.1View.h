
// MFC11.1View.h : CMFC111View 类的接口
//

#pragma once

class CMFC111Set;

class CMFC111View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC111View();
	DECLARE_DYNCREATE(CMFC111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC111_FORM };
#endif
	CMFC111Set* m_pSet;

// 特性
public:
	CMFC111Doc* GetDocument() const;
	CRect picRect;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
};

#ifndef _DEBUG  // MFC11.1View.cpp 中的调试版本
inline CMFC111Doc* CMFC111View::GetDocument() const
   { return reinterpret_cast<CMFC111Doc*>(m_pDocument); }
#endif

