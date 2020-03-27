// MainInformation.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "MainInformation.h"
#include "common.h"
#include "ConnectMysql.h"
#include "Examination.h"
#include "MyInformation.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainInformation dialog


CMainInformation::CMainInformation(CWnd* pParent /*=NULL*/)
	: CDialog(CMainInformation::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainInformation)
	m_days = 0;
	m_hours = 0;
	m_minutes = 0;
	m_seconds = 0;
	//}}AFX_DATA_INIT
}


void CMainInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainInformation)
	DDX_Text(pDX, IDC_DAY, m_days);
	DDX_Text(pDX, IDC_HOUR, m_hours);
	DDX_Text(pDX, IDC_MINUTE, m_minutes);
	DDX_Text(pDX, IDC_SECOND, m_seconds);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainInformation, CDialog)
	//{{AFX_MSG_MAP(CMainInformation)
	ON_BN_CLICKED(IDC_START_EXAM, OnStartExam)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainInformation message handlers

BOOL CMainInformation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMainInformation::OnStartExam() 
{
	// TODO: Add your control notification handler code here
	CExamination my;
	my.DoModal();
	/*CMyInformation my;
	my.DoModal();*/
}

void CMainInformation::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime m_time=CTime::GetCurrentTime();
	if (m_time > examtime)
	{
		KillTimer(1);
		return;
	}
	CTimeSpan m_timespan=examtime-m_time;
	m_days=m_timespan.GetDays();                  //天数
    m_hours=m_timespan.GetHours();                //小时数
    m_minutes=m_timespan.GetMinutes();            //分钟数
    m_seconds=m_timespan.GetSeconds();            //秒数
	

	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}
