
// MFC5View.h : CMFC5View 类的接口
//

#pragma once


class CMFC5View : public CView
{
protected: // 仅从序列化创建
	CMFC5View();
	DECLARE_DYNCREATE(CMFC5View)

// 特性
public:
	CMFC5Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC5View();
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
	afx_msg void OnShowcircle();
};

#ifndef _DEBUG  // MFC5View.cpp 中的调试版本
inline CMFC5Doc* CMFC5View::GetDocument() const
   { return reinterpret_cast<CMFC5Doc*>(m_pDocument); }
#endif

