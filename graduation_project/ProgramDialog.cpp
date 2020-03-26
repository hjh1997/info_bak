// ProgramDialog.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "ProgramDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgramDialog dialog


CProgramDialog::CProgramDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CProgramDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgramDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CProgramDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgramDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgramDialog, CDialog)
	//{{AFX_MSG_MAP(CProgramDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgramDialog message handlers
