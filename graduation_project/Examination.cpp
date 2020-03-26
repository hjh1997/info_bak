// Examination.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExamination::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamination)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExamination, CDialog)
	//{{AFX_MSG_MAP(CExamination)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamination message handlers
