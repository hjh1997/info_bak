#if !defined(AFX_PROGRAMDIALOG_H__C16B1AFF_593B_49AB_8F8A_570B08FBA27B__INCLUDED_)
#define AFX_PROGRAMDIALOG_H__C16B1AFF_593B_49AB_8F8A_570B08FBA27B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgramDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgramDialog dialog

class CProgramDialog : public CDialog
{
// Construction
public:
	CProgramDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgramDialog)
	enum { IDD = IDD_PROGRAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgramDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgramDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAMDIALOG_H__C16B1AFF_593B_49AB_8F8A_570B08FBA27B__INCLUDED_)
