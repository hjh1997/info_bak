#if !defined(AFX_MAININFORMATION_H__A7AF5DC1_EB44_43E1_8576_049F5339BFEA__INCLUDED_)
#define AFX_MAININFORMATION_H__A7AF5DC1_EB44_43E1_8576_049F5339BFEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainInformation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainInformation dialog

class CMainInformation : public CDialog
{
// Construction
public:
	CMainInformation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainInformation)
	enum { IDD = IDD_MAIN_INTERFACE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainInformation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainInformation)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAININFORMATION_H__A7AF5DC1_EB44_43E1_8576_049F5339BFEA__INCLUDED_)
