
// Dlg0View.h : CDlg0View ��Ľӿ�
//

#pragma once


class CDlg0View : public CView
{
protected: // �������л�����
	CDlg0View();
	DECLARE_DYNCREATE(CDlg0View)

// ����
public:
	CDlg0Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CDlg0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // Dlg0View.cpp �еĵ��԰汾
inline CDlg0Doc* CDlg0View::GetDocument() const
   { return reinterpret_cast<CDlg0Doc*>(m_pDocument); }
#endif

