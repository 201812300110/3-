
// MFC5.3Doc.h : CMFC53Doc ��Ľӿ�
//


#pragma once


class CMFC53Doc : public CDocument
{
protected: // �������л�����
	CMFC53Doc();
	DECLARE_DYNCREATE(CMFC53Doc)

// ����
public:
	CRect cr1;
	CRect cr2;
	int a, b, c;
	CPoint p,p1,p2,p3;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC53Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
