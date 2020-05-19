
// MFC13.3Set.cpp : CMFC133Set 类的实现
//

#include "stdafx.h"
#include "MFC13.3.h"
#include "MFC13.3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC133Set 实现

// 代码生成在 2020年5月19日, 19:42

IMPLEMENT_DYNAMIC(CMFC133Set, CRecordset)

CMFC133Set::CMFC133Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_2 = 0;
	m_3 = 0;
	m_4 = 0;
	m_5 = 0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFC133Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x7efc\x5408\x5b9e\x9a8c\x4e09;DBQ=C:\\Users\\\x9ec4\x65ed\x660e\\\x7efc\x5408\x5b9e\x9a8c\x4e09.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC133Set::GetDefaultSQL()
{
	return _T("[综合实验三]");
}

void CMFC133Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[字段1]"), m_1);
	RFX_Long(pFX, _T("[字段2]"), m_2);
	RFX_Long(pFX, _T("[字段3]"), m_3);
	RFX_Long(pFX, _T("[字段4]"), m_4);
	RFX_Long(pFX, _T("[字段5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC133Set 诊断

#ifdef _DEBUG
void CMFC133Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC133Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

