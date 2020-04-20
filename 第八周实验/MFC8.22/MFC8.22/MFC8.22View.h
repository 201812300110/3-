
// MFC8.22View.h : CMFC822View 类的接口
//

#pragma once


class CMFC822View : public CView
{
protected: // 仅从序列化创建
	CMFC822View();
	DECLARE_DYNCREATE(CMFC822View)

// 特性
public:
	CMFC822Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC822View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC8.22View.cpp 中的调试版本
inline CMFC822Doc* CMFC822View::GetDocument() const
   { return reinterpret_cast<CMFC822Doc*>(m_pDocument); }
#endif

