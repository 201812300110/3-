
// MFC7.3View.h : CMFC73View ��Ľӿ�
//

#pragma once


class CMFC73View : public CView
{
protected: // �������л�����
	CMFC73View();
	DECLARE_DYNCREATE(CMFC73View)

// ����
public:
	CMFC73Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC73View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC7.3View.cpp �еĵ��԰汾
inline CMFC73Doc* CMFC73View::GetDocument() const
   { return reinterpret_cast<CMFC73Doc*>(m_pDocument); }
#endif

