
// MFC9.2View.h : CMFC92View 类的接口
//

#pragma once


class CMFC92View : public CView
{
protected: // 仅从序列化创建
	CMFC92View();
	DECLARE_DYNCREATE(CMFC92View)

// 特性
public:
	CMFC92Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC92View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	virtual void Serialize(CArchive& ar);
	//afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC9.2View.cpp 中的调试版本
inline CMFC92Doc* CMFC92View::GetDocument() const
   { return reinterpret_cast<CMFC92Doc*>(m_pDocument); }
#endif

