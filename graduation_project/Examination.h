#if !defined(AFX_EXAMINATION_H__496C03C0_B99E_4C79_A7DD_AEFED52BC23D__INCLUDED_)
#define AFX_EXAMINATION_H__496C03C0_B99E_4C79_A7DD_AEFED52BC23D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Examination.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExamination dialog

class CExamination : public CDialog
{
// Construction
public:
	CExamination(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExamination)
	enum { IDD = IDD_EXAMINATION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamination)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExamination)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMINATION_H__496C03C0_B99E_4C79_A7DD_AEFED52BC23D__INCLUDED_)
