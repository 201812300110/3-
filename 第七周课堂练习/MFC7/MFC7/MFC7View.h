
// MFC7View.h : CMFC7View 类的接口
//

#pragma once


class CMFC7View : public CView
{
protected: // 仅从序列化创建
	CMFC7View();
	DECLARE_DYNCREATE(CMFC7View)

// 特性
public:
	CMFC7Doc* GetDocument() const;

// 操作
public:
	int a;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC7View();
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

#ifndef _DEBUG  // MFC7View.cpp 中的调试版本
inline CMFC7Doc* CMFC7View::GetDocument() const
   { return reinterpret_cast<CMFC7Doc*>(m_pDocument); }
#endif

