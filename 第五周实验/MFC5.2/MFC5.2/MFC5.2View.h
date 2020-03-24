
// MFC5.2View.h : CMFC52View ��Ľӿ�
//

#pragma once


class CMFC52View : public CView
{
protected: // �������л�����
	CMFC52View();
	DECLARE_DYNCREATE(CMFC52View)

// ����
public:
	CMFC52Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap; //λ ͼ����
	int m_nWidth;
	int m_nHeight;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC5.2View.cpp �еĵ��԰汾
inline CMFC52Doc* CMFC52View::GetDocument() const
   { return reinterpret_cast<CMFC52Doc*>(m_pDocument); }
#endif

