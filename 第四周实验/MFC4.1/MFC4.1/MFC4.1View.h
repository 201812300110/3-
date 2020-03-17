
// MFC4.1View.h : CMFC41View 类的接口
//

#pragma once


class CMFC41View : public CView
{
protected: // 仅从序列化创建
	CMFC41View();
	DECLARE_DYNCREATE(CMFC41View)

// 特性
public:
	CMFC41Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4.1View.cpp 中的调试版本
inline CMFC41Doc* CMFC41View::GetDocument() const
   { return reinterpret_cast<CMFC41Doc*>(m_pDocument); }
#endif

