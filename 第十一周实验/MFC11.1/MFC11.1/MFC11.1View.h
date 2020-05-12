
// MFC11.1View.h : CMFC111View ��Ľӿ�
//

#pragma once

class CMFC111Set;

class CMFC111View : public CRecordView
{
protected: // �������л�����
	CMFC111View();
	DECLARE_DYNCREATE(CMFC111View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC111_FORM };
#endif
	CMFC111Set* m_pSet;

// ����
public:
	CMFC111Doc* GetDocument() const;
	CRect picRect;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
};

#ifndef _DEBUG  // MFC11.1View.cpp �еĵ��԰汾
inline CMFC111Doc* CMFC111View::GetDocument() const
   { return reinterpret_cast<CMFC111Doc*>(m_pDocument); }
#endif

