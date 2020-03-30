#if !defined(AFX_MY_SCORE_H__F9760491_EDB3_48D9_A9B9_41491D306DF1__INCLUDED_)
#define AFX_MY_SCORE_H__F9760491_EDB3_48D9_A9B9_41491D306DF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// My_Score.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMy_Score dialog

class CMy_Score : public CDialog
{
// Construction
public:
	CMy_Score(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMy_Score)
	enum { IDD = IDD_SCORE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy_Score)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMy_Score)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MY_SCORE_H__F9760491_EDB3_48D9_A9B9_41491D306DF1__INCLUDED_)
