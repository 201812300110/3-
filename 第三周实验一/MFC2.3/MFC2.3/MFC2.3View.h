
// MFC2.3View.h : CMFC23View 类的接口
//

#pragma once


class CMFC23View : public CView
{
protected: // 仅从序列化创建
	CMFC23View();
	DECLARE_DYNCREATE(CMFC23View)

// 特性
public:
	CMFC23Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC23View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC2.3View.cpp 中的调试版本
inline CMFC23Doc* CMFC23View::GetDocument() const
   { return reinterpret_cast<CMFC23Doc*>(m_pDocument); }
#endif

