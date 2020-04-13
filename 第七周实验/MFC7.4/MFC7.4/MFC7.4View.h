
// MFC7.4View.h : CMFC74View 类的接口
//

#pragma once


class CMFC74View : public CView
{
protected: // 仅从序列化创建
	CMFC74View();
	DECLARE_DYNCREATE(CMFC74View)

// 特性
public:
	CMFC74Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC74View();
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
};

#ifndef _DEBUG  // MFC7.4View.cpp 中的调试版本
inline CMFC74Doc* CMFC74View::GetDocument() const
   { return reinterpret_cast<CMFC74Doc*>(m_pDocument); }
#endif

