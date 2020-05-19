
// MFC13.3View.h : CMFC133View 类的接口
//

#pragma once

class CMFC133Set;

class CMFC133View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC133View();
	DECLARE_DYNCREATE(CMFC133View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC133_FORM };
#endif
	CMFC133Set* m_pSet;

// 特性
public:
	CMFC133Doc* GetDocument() const;

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
	virtual ~CMFC133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString s;
	afx_msg void OnBnClickedButtonDelect();
	afx_msg void OnBnClickedButton1Add();
	long s1;
	afx_msg void OnBnClickedButtonRevise();
};

#ifndef _DEBUG  // MFC13.3View.cpp 中的调试版本
inline CMFC133Doc* CMFC133View::GetDocument() const
   { return reinterpret_cast<CMFC133Doc*>(m_pDocument); }
#endif

