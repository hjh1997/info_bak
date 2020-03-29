// Examination.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "common.h"
#include "Examination.h"
#include "topic.h"
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
	DDX_Control(pDX, IDC_LIST, m_mylist);
	DDX_Text(pDX, IDC_HOUR, m_exam_hour);
	DDX_Text(pDX, IDC_MINUTE, m_exam_minute);
	DDX_Text(pDX, IDC_SECOND, m_exam_second);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExamination, CDialog)
	//{{AFX_MSG_MAP(CExamination)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_DOWN_QUESTION, OnDownQuestion)
	ON_BN_CLICKED(IDC_UP_QUESTION, OnUpQuestion)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamination message handlers

BOOL CExamination::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	GetDlgItem(IDC_QUESTION)->SetWindowText(exam_ques[0]);

	//��ʼ��listctrl
	m_mylist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_mylist.InsertColumn(0, "��Ŀ���", LVCFMT_LEFT, 110);
	m_mylist.InsertColumn(1, "���״̬", LVCFMT_LEFT, 110);
	int k;
	CString str;
	for(k=0;k<answer.size();k++)
	{
		m_mylist.InsertItem(k,"�ؼѺ�");
		if (NULL == answer[k])
			m_mylist.SetItemText(k,1,"δ���");
		str.Format("%d",k+1);
		m_mylist.SetItemText(k,0,str);
	}
	RedrawWindow();
	//SetTimer(2,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExamination::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime m_time=CTime::GetCurrentTime();
	if (m_time > exam_longtime)   //����ʱ�����
	{
		KillTimer(2);
		return;
	}
	CTimeSpan m_timespan=exam_longtime-m_time;
    m_exam_hour=m_timespan.GetHours();                //Сʱ��
    m_exam_minute=m_timespan.GetMinutes();            //������
    m_exam_second=m_timespan.GetSeconds();            //����
	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}

void CExamination::OnDownQuestion() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_QUESTION)->SetWindowText(++exam_ques);
	RedrawWindow();

}

void CExamination::OnUpQuestion() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_QUESTION)->SetWindowText(--exam_ques);
	RedrawWindow();
}

void CExamination::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int count = m_mylist.GetSelectionMark();
	exam_ques.e_set_point(count);
	GetDlgItem(IDC_QUESTION)->SetWindowText(exam_ques[count]);
	RedrawWindow();
	*pResult = 0;
}

void CExamination::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	int current = exam_ques.e_get_current();
	int type = exam_info.get_type(current);
	if(1 == type) //��ѡ ��ֻ��ʾ radio1-4
	{
		GetDlgItem(IDC_STATIC2)->SetWindowText("(��ѡ��)");
		GetDlgItem(IDC_CHECK1)->ShowWindow(false);
		GetDlgItem(IDC_CHECK2)->ShowWindow(false);
		GetDlgItem(IDC_CHECK3)->ShowWindow(false);
		GetDlgItem(IDC_CHECK4)->ShowWindow(false);
		GetDlgItem(IDC_EDIT1)->ShowWindow(false);
		GetDlgItem(IDC_PROGRAME)->ShowWindow(false);
		GetDlgItem(IDC_STATIC1)->ShowWindow(false);
		GetDlgItem(IDC_RADIO1)->ShowWindow(true);
		GetDlgItem(IDC_RADIO2)->ShowWindow(true);
		GetDlgItem(IDC_RADIO3)->ShowWindow(true);
		GetDlgItem(IDC_RADIO4)->ShowWindow(true);
		return;
	}
	if(2 == type) //�ж���  ֻ����radio1-2
	{
		GetDlgItem(IDC_STATIC2)->SetWindowText("(�ж���)");
		GetDlgItem(IDC_CHECK1)->ShowWindow(false);
		GetDlgItem(IDC_CHECK2)->ShowWindow(false);
		GetDlgItem(IDC_CHECK3)->ShowWindow(false);
		GetDlgItem(IDC_CHECK4)->ShowWindow(false);
		GetDlgItem(IDC_EDIT1)->ShowWindow(false);
		GetDlgItem(IDC_PROGRAME)->ShowWindow(false);
		GetDlgItem(IDC_RADIO3)->ShowWindow(false);
		GetDlgItem(IDC_RADIO4)->ShowWindow(false);
		GetDlgItem(IDC_RADIO1)->ShowWindow(true);
		GetDlgItem(IDC_RADIO2)->ShowWindow(true);
		GetDlgItem(IDC_STATIC1)->ShowWindow(true);
		return;
	}
	if(3 == type) //����� ֻ����idet1
	{
		GetDlgItem(IDC_STATIC2)->SetWindowText("(�����)");
		GetDlgItem(IDC_STATIC1)->ShowWindow(false);
		GetDlgItem(IDC_CHECK1)->ShowWindow(false);
		GetDlgItem(IDC_CHECK2)->ShowWindow(false);
		GetDlgItem(IDC_CHECK3)->ShowWindow(false);
		GetDlgItem(IDC_CHECK4)->ShowWindow(false);
		GetDlgItem(IDC_PROGRAME)->ShowWindow(false);
		GetDlgItem(IDC_RADIO3)->ShowWindow(false);
		GetDlgItem(IDC_RADIO4)->ShowWindow(false);
		GetDlgItem(IDC_RADIO1)->ShowWindow(false);
		GetDlgItem(IDC_RADIO2)->ShowWindow(false);
		GetDlgItem(IDC_EDIT1)->ShowWindow(true);
		return;
	}
	if(4 == type) //��ѡ ֻ����check1-4
	{
		GetDlgItem(IDC_STATIC2)->SetWindowText("(��ѡ��)");
		GetDlgItem(IDC_STATIC1)->ShowWindow(false);
		GetDlgItem(IDC_PROGRAME)->ShowWindow(false);
		GetDlgItem(IDC_RADIO3)->ShowWindow(false);
		GetDlgItem(IDC_RADIO4)->ShowWindow(false);
		GetDlgItem(IDC_RADIO1)->ShowWindow(false);
		GetDlgItem(IDC_RADIO2)->ShowWindow(false);
		GetDlgItem(IDC_EDIT1)->ShowWindow(false);
		GetDlgItem(IDC_CHECK1)->ShowWindow(true);
		GetDlgItem(IDC_CHECK2)->ShowWindow(true);
		GetDlgItem(IDC_CHECK3)->ShowWindow(true);
		GetDlgItem(IDC_CHECK4)->ShowWindow(true);
	}
	if(5 == type) //����� ֻ����programe
	{
		GetDlgItem(IDC_STATIC2)->SetWindowText("(�����)");
		GetDlgItem(IDC_STATIC1)->ShowWindow(false);
		GetDlgItem(IDC_CHECK1)->ShowWindow(false);
		GetDlgItem(IDC_CHECK2)->ShowWindow(false);
		GetDlgItem(IDC_CHECK3)->ShowWindow(false);
		GetDlgItem(IDC_CHECK4)->ShowWindow(false);
		GetDlgItem(IDC_RADIO3)->ShowWindow(false);
		GetDlgItem(IDC_RADIO4)->ShowWindow(false);
		GetDlgItem(IDC_RADIO1)->ShowWindow(false);
		GetDlgItem(IDC_RADIO2)->ShowWindow(false);
		GetDlgItem(IDC_EDIT1)->ShowWindow(false);
		GetDlgItem(IDC_PROGRAME)->ShowWindow(true);
		return;
	}
	AfxMessageBox("�Ƿ�ִ��");
	// Do not call CDialog::OnPaint() for painting messages
}
