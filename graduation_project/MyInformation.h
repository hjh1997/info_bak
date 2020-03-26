#if !defined(AFX_MYINFORMATION_H__93ADF928_6F83_45F0_B3E7_8BBFA2B2E0CA__INCLUDED_)
#define AFX_MYINFORMATION_H__93ADF928_6F83_45F0_B3E7_8BBFA2B2E0CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyInformation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyInformation dialog

class CMyInformation : public CDialog
{
// Construction
public:
	CMyInformation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyInformation)
	enum { IDD = IDD_MY_INFOMATION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyInformation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyInformation)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYINFORMATION_H__93ADF928_6F83_45F0_B3E7_8BBFA2B2E0CA__INCLUDED_)
