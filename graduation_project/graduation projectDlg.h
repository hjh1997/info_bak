// graduation projectDlg.h : header file
//

#if !defined(AFX_GRADUATIONPROJECTDLG_H__6B7C5CC5_05F6_4A66_908E_767DFCDD7BEA__INCLUDED_)
#define AFX_GRADUATIONPROJECTDLG_H__6B7C5CC5_05F6_4A66_908E_767DFCDD7BEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGraduationprojectDlg dialog

class CGraduationprojectDlg : public CDialog
{
// Construction
public:
	CGraduationprojectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGraduationprojectDlg)
	enum { IDD = IDD_GRADUATIONPROJECT_DIALOG };
	CString	m_stu_id;
	CString	m_stu_password;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraduationprojectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGraduationprojectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADUATIONPROJECTDLG_H__6B7C5CC5_05F6_4A66_908E_767DFCDD7BEA__INCLUDED_)
