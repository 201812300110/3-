
// MFC9View.h : CMFC9View 类的接口
//

#pragma once


class CMFC9View : public CView
{
protected: // 仅从序列化创建
	CMFC9View();
	DECLARE_DYNCREATE(CMFC9View)

// 特性
public:
	CMFC9Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFC9View.cpp 中的调试版本
inline CMFC9Doc* CMFC9View::GetDocument() const
   { return reinterpret_cast<CMFC9Doc*>(m_pDocument); }
#endif

