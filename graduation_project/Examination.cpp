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
	ON_BN_CLICKED(IDC_CONFIRE, OnConfire)
	ON_BN_CLICKED(IDC_COMMIT_PAPER, OnCommitPaper)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamination message handlers

BOOL CExamination::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	//初始化题目
	GetDlgItem(IDC_QUESTION)->SetWindowText(exam_ques[0]);

	//初始化listctrl
	m_mylist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_mylist.InsertColumn(0, "题目序号", LVCFMT_LEFT, 110);
	m_mylist.InsertColumn(1, "完成状态", LVCFMT_LEFT, 110);
	int k;
	CString str;
	for(k=0;k<answer.size();k++)
	{
		m_mylist.InsertItem(k,"贺佳豪");
		if (NULL == answer[k])
			m_mylist.SetItemText(k,1,"未完成");
		else
			m_mylist.SetItemText(k,1,"已完成");
		str.Format("%d",k+1);
		m_mylist.SetItemText(k,0,str);
	}
	RedrawWindow();
	//CMenu* pMenu = this->GetSystemMenu(FALSE);//系统菜单
	//pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );
	//SetTimer(2,1000,NULL);
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
	
	if(1 == type) //单选 ，只显示 radio1-4
	{
		CString str;
		str.Format("(单选题)%0.1f分",exam_info.score[current]);
		GetDlgItem(IDC_STATIC2)->SetWindowText(str);
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
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(0);
		if(NULL != answer[current])
		{
			if(*answer[current] == 'A')
				((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(1);
			else if(*answer[current] == 'B')
				((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(1);
			else if(*answer[current] == 'C')
				((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(1);
			else if(*answer[current] == 'D')
				((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(1);
		}
		return;
	}
	if(2 == type) //判断题  只保留radio1-2
	{
		CString str;
		str.Format("(判断题)%0.1f分",exam_info.score[current]);
		GetDlgItem(IDC_STATIC2)->SetWindowText(str);
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
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		if(NULL != answer[current])
		{
			if(*answer[current] == 'A')
				((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(1);
			else if(*answer[current] == 'B')
				((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(1);
		}
		return;
	}
	if(3 == type) //填空题 只保留idet1
	{
		CString str;
		str.Format("(填空题)%0.1f分",exam_info.score[current]);
		GetDlgItem(IDC_STATIC2)->SetWindowText(str);
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
		GetDlgItem(IDC_EDIT1)->SetWindowText("");
		if(NULL != answer[current])
		{
			CString str(answer[current]);
				GetDlgItem(IDC_EDIT1)->SetWindowText(str);
		}
		return;
	}
	if(4 == type) //多选 只保留check1-4
	{
		CString str;
		str.Format("(多选题)%0.1f分",exam_info.score[current]);
		GetDlgItem(IDC_STATIC2)->SetWindowText(str);
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
		((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(0);
		((CButton *)GetDlgItem(IDC_CHECK4))->SetCheck(0);
		if(NULL != answer[current])
		{
			char *p = answer[current];
			if(*p == 'A')
			{
				((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(1);
				p++;
			}
			if(*p == 'B')
			{
				((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(1);
				p++;
			}
			if(*p == 'C')
			{
				((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(1);
				p++;
			}
			if(*p == 'D')
				((CButton *)GetDlgItem(IDC_CHECK4))->SetCheck(1);
		}
		return;
	}
	if(5 == type) //编程题 只保留programe
	{
		CString str;
		str.Format("(编程题)%0.1f分",exam_info.score[current]);
		GetDlgItem(IDC_STATIC2)->SetWindowText(str);
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
	AfxMessageBox("是否执行");
	// Do not call CDialog::OnPaint() for painting messages
}
//要确保 用户在不做点击提交的情况
void CExamination::OnConfire() 
{
	// TODO: Add your control notification handler code here
	int current = exam_ques.e_get_current();
	int type = exam_info.get_type(current);
	if (NULL == answer[current])   //如果没有填写答案，则为其申请空间，保存答案
	{
		char *p =NULL;
		char str;
		CString str1;
		char *Source;
		//对题目类型判断应该获取哪一个控件的值 to do here
		switch(type)
		{
		case 1:
			if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
				str='A';
			else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck())
				str='B';
			else if (((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck())
				str='C';
			else if (((CButton *)GetDlgItem(IDC_RADIO4))->GetCheck())
				str='D';
			else
			{
				AfxMessageBox("请选择答案后提交!");
				return;
			}
			p = new char[2];
			memset(p,'\0',2);
			strncpy(p,&str,1);
			AfxMessageBox(p);
			answer[current] = p; //让答案的指针改变
			break;
		case 2:
			if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
				str='A';
			else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck())
				str='B';
			else
			{
				AfxMessageBox("请选择答案后提交!");
				return;
			}
			p = new char[2];
			memset(p,0,2);
			strncpy(p,&str,1);
			answer[current] = p;
			break;
		case 3:
			GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
			if(str1.IsEmpty())
			{
				AfxMessageBox("请填写答案后提交!");
				return;
			}
			Source= (char*)(LPCTSTR)str1;
			p = new char[strlen(Source)+1];
			memset(p,0,strlen(Source)+1);
			strcpy(p,Source);
			answer[current] = p;
			break;
		case 4:   //多选
			if (((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck())
				str1="A";
			if (((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck())
				str1=str1+"B";
			if (((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck())
				str1=str1+"C";
			if (((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck())
				str1=str1+"D";
			if (str1.IsEmpty())
			{
				AfxMessageBox("请选择答案后提交!");
				return;
			}
			AfxMessageBox(str1);
			Source= (char*)(LPCTSTR)str1;
			p = new char[strlen(Source)+1];
			memset(p,0,strlen(Source)+1);
			strcpy(p,Source);
			answer[current] = p;
			break;
		case 5:
			AfxMessageBox("请在编程题界面提交！");
			break;
		}
		m_mylist.SetItemText(current,1,"已完成");
		GetDlgItem(IDC_QUESTION)->SetWindowText(++exam_ques);//更换下一个题目
		RedrawWindow();
		return;
	}
	else
	{
		AfxMessageBox("您已经答过此题！请您继续作答其他题目");
		return;
	}
}

void CExamination::OnCommitPaper() 
{
	// TODO: Add your control notification handler code here
	int count = m_mylist.GetItemCount();
	int i=0;
	char *str = "未完成";
	int flag =0;
	for(i;i<count;i++)  //判断是否有未完成题目
	{
		char ptr[20];
		memset(ptr,0,20);
		m_mylist.GetItemText(i,1,ptr,20);
		if(0 == strcmp(str,ptr))
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		if(MessageBox(_T("你有未完成的试题，确定要提交吗？"),\
_T("提示"),MB_YESNO|MB_ICONWARNING)  == IDNO)
			return;
	}
	EndDialog(3);
}

void CExamination::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnClose();
}
