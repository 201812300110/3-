
// MFC7.4View.h : CMFC74View ��Ľӿ�
//

#pragma once


class CMFC74View : public CView
{
protected: // �������л�����
	CMFC74View();
	DECLARE_DYNCREATE(CMFC74View)

// ����
public:
	CMFC74Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC74View();
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
};

#ifndef _DEBUG  // MFC7.4View.cpp �еĵ��԰汾
inline CMFC74Doc* CMFC74View::GetDocument() const
   { return reinterpret_cast<CMFC74Doc*>(m_pDocument); }
#endif

