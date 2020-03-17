
// MFC4.3View.h : CMFC43View 类的接口
//

#pragma once


class CMFC43View : public CView
{
protected: // 仅从序列化创建
	CMFC43View();
	DECLARE_DYNCREATE(CMFC43View)

// 特性
public:
	CMFC43Doc* GetDocument() const;

// 操作
public:
	bool set;
	CArray<CRect,CRect> cr;
	int b;
	int d;


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC4.3View.cpp 中的调试版本
inline CMFC43Doc* CMFC43View::GetDocument() const
   { return reinterpret_cast<CMFC43Doc*>(m_pDocument); }
#endif

