// graduation project.h : main header file for the GRADUATION PROJECT application
//

#if !defined(AFX_GRADUATIONPROJECT_H__90994D2E_2D0E_47BB_994E_735AF31B932E__INCLUDED_)
#define AFX_GRADUATIONPROJECT_H__90994D2E_2D0E_47BB_994E_735AF31B932E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGraduationprojectApp:
// See graduation project.cpp for the implementation of this class
//

class CGraduationprojectApp : public CWinApp
{
public:
	CGraduationprojectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraduationprojectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGraduationprojectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADUATIONPROJECT_H__90994D2E_2D0E_47BB_994E_735AF31B932E__INCLUDED_)
