
// MFC7.2View.h : CMFC72View 类的接口
//

#pragma once


class CMFC72View : public CView
{
protected: // 仅从序列化创建
	CMFC72View();
	DECLARE_DYNCREATE(CMFC72View)

// 特性
public:
	CMFC72Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC72View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopou();
};

#ifndef _DEBUG  // MFC7.2View.cpp 中的调试版本
inline CMFC72Doc* CMFC72View::GetDocument() const
   { return reinterpret_cast<CMFC72Doc*>(m_pDocument); }
#endif

