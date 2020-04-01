
// MFC6View.h : CMFC6View 类的接口
//

#pragma once


class CMFC6View : public CView
{
protected: // 仅从序列化创建
	CMFC6View();
	DECLARE_DYNCREATE(CMFC6View)

// 特性
public:
	CMFC6Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC6View();
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
};

#ifndef _DEBUG  // MFC6View.cpp 中的调试版本
inline CMFC6Doc* CMFC6View::GetDocument() const
   { return reinterpret_cast<CMFC6Doc*>(m_pDocument); }
#endif

