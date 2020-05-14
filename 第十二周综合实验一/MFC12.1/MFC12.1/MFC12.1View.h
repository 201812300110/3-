
// MFC12.1View.h : CMFC121View 类的接口
//

#pragma once

class CMFC121Set;

class CMFC121View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC121View();
	DECLARE_DYNCREATE(CMFC121View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC121_FORM };
#endif
	CMFC121Set* m_pSet;

// 特性
public:
	CMFC121Doc* GetDocument() const;
	void draw_pic(CString file);
// 操作
public:
	CString path, filename, s;
	CRect picRect;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC121View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString a;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC12.1View.cpp 中的调试版本
inline CMFC121Doc* CMFC121View::GetDocument() const
   { return reinterpret_cast<CMFC121Doc*>(m_pDocument); }
#endif

