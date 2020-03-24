
// MFC5.3View.h : CMFC53View 类的接口
//

#pragma once


class CMFC53View : public CView
{
protected: // 仅从序列化创建
	CMFC53View();
	DECLARE_DYNCREATE(CMFC53View)

// 特性
public:
	CMFC53Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC53View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowline();
	afx_msg void OnShowround();
	afx_msg void OnShowellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC5.3View.cpp 中的调试版本
inline CMFC53Doc* CMFC53View::GetDocument() const
   { return reinterpret_cast<CMFC53Doc*>(m_pDocument); }
#endif

