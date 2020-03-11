
// MFC2.2View.h : CMFC22View 类的接口
//

#pragma once


class CMFC22View : public CView
{
protected: // 仅从序列化创建
	CMFC22View();
	DECLARE_DYNCREATE(CMFC22View)

// 特性
public:
	CMFC22Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&> ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC22View();
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
};

#ifndef _DEBUG  // MFC2.2View.cpp 中的调试版本
inline CMFC22Doc* CMFC22View::GetDocument() const
   { return reinterpret_cast<CMFC22Doc*>(m_pDocument); }
#endif

