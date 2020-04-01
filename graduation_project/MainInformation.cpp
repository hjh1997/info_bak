// MainInformation.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "MainInformation.h"
#include "common.h"
#include "ConnectMysql.h"
#include "Examination.h"
#include "MyInformation.h"
#include "My_Score.h"
bool is_finished = 0;
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
	ON_BN_CLICKED(IDC_CANCLE, OnCancle)
	ON_COMMAND(ID_MENU_INFO, OnMenuInfo)
	ON_COMMAND(ID_MENU_SCORE, OnMenuScore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainInformation message handlers

BOOL CMainInformation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	GetDlgItem(IDC_EXAM_TIME)->SetWindowText(exam_long);
	// TODO: Add extra initialization here
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMainInformation::OnStartExam() 
{
	// TODO: Add your control notification handler code here
	CExamination my;
	int res = my.DoModal();
	if(3 == res)
	{
		GetDlgItem(IDC_START_EXAM)->SetWindowText("���Խ���");
		GetDlgItem(IDC_START_EXAM)->EnableWindow(FALSE);
		AfxMessageBox("���Խ�������������\"�ɼ���ѯ\"�в鿴���Ĵ˴ο��Գɼ���");
	}
	else
	{
		AfxMessageBox("������;�����������Ե�� ��ʼ���� ��������");
		return;
	}
	float result = calculate();
	is_finished = 1;
	CString str;
	str.Format("%f",result);
	AfxMessageBox(str);
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
	m_days=m_timespan.GetDays();                  //����
    m_hours=m_timespan.GetHours();                //Сʱ��
    m_minutes=m_timespan.GetMinutes();            //������
    m_seconds=m_timespan.GetSeconds();            //����
	

	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}

void CMainInformation::OnCancle() 
{
	// TODO: Add your control notification handler code here
	if (MessageBox(_T("��ȷ���˳���?"), _T("��ʾ"),MB_YESNO|MB_ICONWARNING)  == IDNO)
	     return;
	EndDialog(1);
}

void CMainInformation::OnMenuInfo() 
{
	// TODO: Add your command handler code here
	CMyInformation myinfo;
	myinfo.DoModal();
}

void CMainInformation::OnMenuScore() 
{
	// TODO: Add your command handler code here
	if(!is_finished)
	{
		AfxMessageBox("����û�вμӿ��ԣ��޷��鿴�ɼ�!");
		return;
	}
	CMy_Score myscore; //û����һ������
	myscore.DoModal();
}
