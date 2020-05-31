
// MFC14Set.cpp : CMFC14Set 类的实现
//

#include "stdafx.h"
#include "MFC14.h"
#include "MFC14Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC14Set 实现

// 代码生成在 2020年5月25日, 20:54

IMPLEMENT_DYNAMIC(CMFC14Set, CRecordset)

CMFC14Set::CMFC14Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_2 = L"";
	m_3 = 0;
	m_11 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFC14Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x57fa\x672c\x4fe1\x606f;DBQ=C:\\Users\\\x9ec4\x65ed\x660e\\\x5b66\x751f\x57fa\x672c\x4fe1\x606f.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC14Set::GetDefaultSQL()
{
	return _T("[学生基本信息]");
}

void CMFC14Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[学号]"), m_1);
	RFX_Text(pFX, _T("[姓名]"), m_2);
	RFX_Long(pFX, _T("[年龄]"), m_3);
	RFX_Text(pFX, _T("[图片路径]"), m_11);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC14Set 诊断

#ifdef _DEBUG
void CMFC14Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC14Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

