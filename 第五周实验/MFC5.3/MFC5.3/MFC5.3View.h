
// MFC5.3View.h : CMFC53View ��Ľӿ�
//

#pragma once


class CMFC53View : public CView
{
protected: // �������л�����
	CMFC53View();
	DECLARE_DYNCREATE(CMFC53View)

// ����
public:
	CMFC53Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC53View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowline();
	afx_msg void OnShowround();
	afx_msg void OnShowellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC5.3View.cpp �еĵ��԰汾
inline CMFC53Doc* CMFC53View::GetDocument() const
   { return reinterpret_cast<CMFC53Doc*>(m_pDocument); }
#endif

