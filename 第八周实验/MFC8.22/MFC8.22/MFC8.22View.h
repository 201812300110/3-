
// MFC8.22View.h : CMFC822View ��Ľӿ�
//

#pragma once


class CMFC822View : public CView
{
protected: // �������л�����
	CMFC822View();
	DECLARE_DYNCREATE(CMFC822View)

// ����
public:
	CMFC822Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC822View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC8.22View.cpp �еĵ��԰汾
inline CMFC822Doc* CMFC822View::GetDocument() const
   { return reinterpret_cast<CMFC822Doc*>(m_pDocument); }
#endif

