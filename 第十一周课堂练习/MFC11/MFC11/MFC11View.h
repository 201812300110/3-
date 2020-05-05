
// MFC11View.h : CMFC11View 类的接口
//

#pragma once

class CMFC11Set;

class CMFC11View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC11View();
	DECLARE_DYNCREATE(CMFC11View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC11_FORM };
#endif
	CMFC11Set* m_pSet;

// 特性
public:
	CMFC11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFC11View();
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
	CString phone;
};

#ifndef _DEBUG  // MFC11View.cpp 中的调试版本
inline CMFC11Doc* CMFC11View::GetDocument() const
   { return reinterpret_cast<CMFC11Doc*>(m_pDocument); }
#endif

