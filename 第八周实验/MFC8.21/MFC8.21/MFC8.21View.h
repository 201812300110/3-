
// MFC8.21View.h : CMFC821View ��Ľӿ�
//

#pragma once


class CMFC821View : public CView
{
protected: // �������л�����
	CMFC821View();
	DECLARE_DYNCREATE(CMFC821View)

// ����
public:
	CMFC821Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC821View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC8.21View.cpp �еĵ��԰汾
inline CMFC821Doc* CMFC821View::GetDocument() const
   { return reinterpret_cast<CMFC821Doc*>(m_pDocument); }
#endif

