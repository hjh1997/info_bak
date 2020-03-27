// graduation projectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "graduation project.h"
#include "graduation projectDlg.h"
#include "common.h"
#include "ConnectMysql.h"
#include "MainInformation.h"

CTime examtime;
CTime exam_longtime;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraduationprojectDlg dialog

CGraduationprojectDlg::CGraduationprojectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGraduationprojectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGraduationprojectDlg)
	m_stu_id = _T("");
	m_stu_password = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGraduationprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGraduationprojectDlg)
	DDX_Text(pDX, IDC_STU_ID, m_stu_id);
	DDV_MaxChars(pDX, m_stu_id, 20);
	DDX_Text(pDX, IDC_STU_PASSWORD, m_stu_password);
	DDV_MaxChars(pDX, m_stu_password, 20);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGraduationprojectDlg, CDialog)
	//{{AFX_MSG_MAP(CGraduationprojectDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraduationprojectDlg message handlers

BOOL CGraduationprojectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGraduationprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGraduationprojectDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGraduationprojectDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGraduationprojectDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	ConnectSql();
	//严重密码是否正确
	CString sql1 = "select * from Information where stu_number =\""+m_stu_id+"\"";
	char *str1 = (char*)(LPCTSTR)sql1;
	Query(str1);
	MYSQL_ROW row=NULL;
	row=mysql_fetch_row(result);
	CString re = row[1];
	if (0 == m_stu_password.Compare(re))
	{
		AfxMessageBox("登录成功");
	}
	else
	{
		AfxMessageBox("密码错误，请重试");
		return;
	}
	//1表示考试场次,登录后会连接数据库获取考试信息
	CString sql = "select * from examtime where exam_session =1"; 
	char *str = (char*)(LPCTSTR)sql;
	Query(str);
	row=mysql_fetch_row(result);
	CString res(row[1]);  //获取考试日期
	CString res1(row[2]); //获取考试时长
	//将CString转化为CTimespan;
	CTimeSpan span = CstringtoCtimespan(res1); 
    // 将CString 转换为Ctime类型
	examtime = CStringtoCtime(res);
	//计算出考试最终结束的时间，然后减去当前的时间 就是倒计时的时间。
	exam_longtime = examtime+span;

	CMainInformation mainframe;
	mainframe.DoModal();
	mysql_free_result(result);
	mysql_close(&mysql);
	mysql_library_end();
/*	
    测试成功
	// 获取edit 信息。
	UpdateData();
	//连接数据库	
	ConnectSql();
	CString sql = "select * from Information where stu_number =\""+m_stu_id+"\"";
	AfxMessageBox(sql);

	char *str = (char*)(LPCTSTR)sql;
	//AfxMessageBox(tmp);
	Query(str);

	int rowcount=mysql_num_rows(result);  //获取返回结果的行数
	MYSQL_ROW row=NULL;
	row=mysql_fetch_row(result); //获取每行数据 
	CString res = row[1];
	AfxMessageBox(res);
	if (0 == m_stu_password.Compare(res))
	{
		AfxMessageBox("登录成功");
	}
	else
		AfxMessageBox("密码错误，请重试");
*/
}
