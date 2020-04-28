
// MFC10View.h : CMFC10View 类的接口
//

#pragma once


class CMFC10View : public CView
{
protected: // 仅从序列化创建
	CMFC10View();
	DECLARE_DYNCREATE(CMFC10View)

// 特性
public:
	CMFC10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC10View.cpp 中的调试版本
inline CMFC10Doc* CMFC10View::GetDocument() const
   { return reinterpret_cast<CMFC10Doc*>(m_pDocument); }
#endif

