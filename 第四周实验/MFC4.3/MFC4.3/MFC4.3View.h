
// MFC4.3View.h : CMFC43View ��Ľӿ�
//

#pragma once


class CMFC43View : public CView
{
protected: // �������л�����
	CMFC43View();
	DECLARE_DYNCREATE(CMFC43View)

// ����
public:
	CMFC43Doc* GetDocument() const;

// ����
public:
	bool set;
	CArray<CRect,CRect> cr;
	int b;
	int d;


// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC4.3View.cpp �еĵ��԰汾
inline CMFC43Doc* CMFC43View::GetDocument() const
   { return reinterpret_cast<CMFC43Doc*>(m_pDocument); }
#endif

