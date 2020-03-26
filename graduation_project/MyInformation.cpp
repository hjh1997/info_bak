// MyInformation.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "MyInformation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyInformation dialog


CMyInformation::CMyInformation(CWnd* pParent /*=NULL*/)
	: CDialog(CMyInformation::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyInformation)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyInformation)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyInformation, CDialog)
	//{{AFX_MSG_MAP(CMyInformation)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyInformation message handlers
