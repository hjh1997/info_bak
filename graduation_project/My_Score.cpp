// My_Score.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "My_Score.h"

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
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy_Score message handlers
