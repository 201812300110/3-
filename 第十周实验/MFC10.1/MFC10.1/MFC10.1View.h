
// MFC10.1View.h : CMFC101View 类的接口
//

#pragma once


class CMFC101View : public CView
{
protected: // 仅从序列化创建
	CMFC101View();
	DECLARE_DYNCREATE(CMFC101View)

// 特性
public:
	CMFC101Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC101View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC10.1View.cpp 中的调试版本
inline CMFC101Doc* CMFC101View::GetDocument() const
   { return reinterpret_cast<CMFC101Doc*>(m_pDocument); }
#endif

