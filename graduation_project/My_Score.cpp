// My_Score.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "My_Score.h"
#include "common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy_Score dialog


CMy_Score::CMy_Score(CWnd* pParent /*=NULL*/)
	: CDialog(CMy_Score::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy_Score)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMy_Score::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy_Score)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMy_Score, CDialog)
	//{{AFX_MSG_MAP(CMy_Score)
	ON_BN_CLICKED(IDC_SURE, OnSure)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy_Score message handlers

BOOL CMy_Score::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	/*extern float score;           //表示当前得分
    extern float choice;
    extern float istrue;
    extern float gapfill;
    extern flat programe;
    extern int choice_n;
	extern int istrue_n;
	extern int gapfill_n;
	extern int programe_n;
	choice_p;
	extern float istrue_p;
	extern float gapfill_p;
	extern float programe_p;
	*/
	CString str;
	str.Format("选择题一共 %d道题,总分:%.1f。您得分:%.1f",choice_n,choice,choice_p);
	GetDlgItem(IDC_STATIC_CHOICE)->SetWindowText(str);

	str.Empty();
	str.Format("判断题一共 %d道题,总分:%.1f。您得分:%.1f",istrue_n,istrue,istrue_p);
	GetDlgItem(IDC_STATIC_ISTRUE)->SetWindowText(str);

	str.Empty();
	str.Format("填空题一共 %d道题,总分:%.1f。您得分:%.1f",gapfill_n,gapfill,gapfill_p);
	GetDlgItem(IDC_STATIC_GAPFILL)->SetWindowText(str);

	str.Empty();
	str.Format("编程题一共 %d道题,总分:%.1f。您得分:%.1f",programe_n,programe,programe_p);
	GetDlgItem(IDC_STATIC_PROGRAMER)->SetWindowText(str);

	str.Empty();
	str.Format("您的此次考试总成绩为: %.1f 分",score);
	GetDlgItem(IDC_STATIC1)->SetWindowText(str);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMy_Score::OnSure() 
{
	// TODO: Add your control notification handler code here
	EndDialog(1);
}
