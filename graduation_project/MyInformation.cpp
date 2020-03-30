// MyInformation.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "MyInformation.h"
#include "studentInfo.h"
#include "ConnectMysql.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyInformation dialog


CMyInformation::CMyInformation(CWnd* pParent /*=NULL*/)
	: CDialog(CMyInformation::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyInformation)
	m_id = _T("");
	m_name = _T("");
	m_class = _T("");
	m_phone = _T("");
	//}}AFX_DATA_INIT
}


void CMyInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyInformation)
	DDX_Control(pDX, IDC_MAJOR, m_major);
	DDX_Text(pDX, IDC_STU_ID, m_id);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_CLASS, m_class);
	DDX_Text(pDX, IDC_PHONE, m_phone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyInformation, CDialog)
	//{{AFX_MSG_MAP(CMyInformation)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyInformation message handlers

BOOL CMyInformation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_id = CString(student.stu_number);
	m_name = CString(student.stu_name);
	m_class = CString(student.stu_class);
	m_phone = CString(student.stu_phone);

	UpdateData(false);
	if(atol(m_phone) == 0)
		GetDlgItem(IDC_PHONE)->SetWindowText("");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyInformation::OnChange() 
{
	//stu_phone="18292736215"  WHERE stu_number ="201607071216";
	// TODO: Add your control notification handler code here
	UpdateData();
	ConnectSql();
	CString sql = "update information set stu_phone=\""+m_phone+"\""+"where stu_number =\""+m_id+"\"";
	AfxMessageBox(sql);
	char *str1 = (char*)(LPCTSTR)sql;
	Query(str1);
	//mysql_free_result(result);
	mysql_close(&mysql);
	mysql_library_end();
}
