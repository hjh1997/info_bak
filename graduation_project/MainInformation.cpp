// MainInformation.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "MainInformation.h"

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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainInformation)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainInformation, CDialog)
	//{{AFX_MSG_MAP(CMainInformation)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainInformation message handlers
