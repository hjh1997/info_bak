// Examination.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "common.h"
#include "Examination.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExamination dialog


CExamination::CExamination(CWnd* pParent /*=NULL*/)
	: CDialog(CExamination::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExamination)
	m_exam_hour = 0;
	m_exam_minute = 0;
	m_exam_second = 0;
	//}}AFX_DATA_INIT
}


void CExamination::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamination)
	DDX_Text(pDX, IDC_HOUR, m_exam_hour);
	DDX_Text(pDX, IDC_MINUTE, m_exam_minute);
	DDX_Text(pDX, IDC_SECOND, m_exam_second);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExamination, CDialog)
	//{{AFX_MSG_MAP(CExamination)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamination message handlers

BOOL CExamination::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	SetTimer(2,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExamination::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime m_time=CTime::GetCurrentTime();
	if (m_time > exam_longtime)   //考试时间结束
	{
		KillTimer(2);
		return;
	}
	CTimeSpan m_timespan=exam_longtime-m_time;
    m_exam_hour=m_timespan.GetHours();                //小时数
    m_exam_minute=m_timespan.GetMinutes();            //分钟数
    m_exam_second=m_timespan.GetSeconds();            //秒数
	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}
