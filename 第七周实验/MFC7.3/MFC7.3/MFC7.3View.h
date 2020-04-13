
// MFC7.3View.h : CMFC73View 类的接口
//

#pragma once


class CMFC73View : public CView
{
protected: // 仅从序列化创建
	CMFC73View();
	DECLARE_DYNCREATE(CMFC73View)

// 特性
public:
	CMFC73Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC73View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC7.3View.cpp 中的调试版本
inline CMFC73Doc* CMFC73View::GetDocument() const
   { return reinterpret_cast<CMFC73Doc*>(m_pDocument); }
#endif

