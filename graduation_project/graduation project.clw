; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGraduationprojectDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "graduation project.h"

ClassCount=7
Class1=CGraduationprojectApp
Class2=CGraduationprojectDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EXAMINATION
Resource4=IDD_GRADUATIONPROJECT_DIALOG
Resource5=IDD_MAIN_INTERFACE
Resource6=IDD_PROGRAME
Resource7=IDD_MY_INFOMATION
Class4=CMainInformation
Class5=CMyInformation
Class6=CProgramDialog
Class7=CExamination
Resource8=IDR_MENU1

[CLS:CGraduationprojectApp]
Type=0
HeaderFile=graduation project.h
ImplementationFile=graduation project.cpp
Filter=N

[CLS:CGraduationprojectDlg]
Type=0
HeaderFile=graduation projectDlg.h
ImplementationFile=graduation projectDlg.cpp
Filter=D
LastObject=CGraduationprojectDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=graduation projectDlg.h
ImplementationFile=graduation projectDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GRADUATIONPROJECT_DIALOG]
Type=1
Class=CGraduationprojectDlg
ControlCount=6
Control1=IDC_STATIC_ID,static,1342308353
Control2=IDC_STATIC_PASSWORD,static,1342177281
Control3=IDC_STU_ID,edit,1350631552
Control4=IDC_STU_PASSWORD,edit,1350631584
Control5=IDC_LOGIN,button,1342242816
Control6=IDC_CANCLE,button,1342242816

[DLG:IDD_MAIN_INTERFACE]
Type=1
Class=CMainInformation
ControlCount=0

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENU_INFO
Command2=ID_MENU_SCORE
Command3=ID_MENU_HELP
CommandCount=3

[DLG:IDD_MY_INFOMATION]
Type=1
Class=CMyInformation
ControlCount=12
Control1=IDC_STATIC_ID,static,1342308352
Control2=IDC_STATIC_NAME,static,1342308352
Control3=IDC_STATIC_CLASS,static,1342308352
Control4=IDC_STATIC_PHONE,static,1342177280
Control5=IDC_STATIC_MAJOR,static,1342308352
Control6=IDC_STU_ID,edit,1350631552
Control7=IDC_NAME,edit,1350631552
Control8=IDC_OK,button,1342242816
Control9=IDC_CLASS,edit,1350631552
Control10=IDC_CANCLE,button,1342242816
Control11=IDC_PHONE,edit,1350631552
Control12=IDC_MAJOR,combobox,1344340226

[DLG:IDD_EXAMINATION]
Type=1
Class=CExamination
ControlCount=21
Control1=IDC_RICHEDIT1,RICHEDIT,1486946308
Control2=IDC_STATIC_QUESTION,button,1342177287
Control3=IDC_STATIC_STATE,button,1342177287
Control4=IDC_LIST2,SysListView32,1350631424
Control5=IDC_STATIC_ANSWER,button,1342177287
Control6=IDC_STATIC_CHOICE,static,1342177280
Control7=IDC_CHECK_A,button,1342373891
Control8=IDC_CHECK_B,button,1342242819
Control9=IDC_CHECK_C,button,1342242819
Control10=IDC_CHECK_D,button,1342242819
Control11=IDC_STATIC_JUDGEMENT,static,1342177280
Control12=IDC_RADIO_TRUE,button,1342308361
Control13=IDC_RADIO_FALSE,button,1342177289
Control14=IDC_STATIC_GAP,static,1342177280
Control15=IDC_EDIT1,edit,1350631552
Control16=IDC_STATIC_PROGRAME,static,1342177280
Control17=IDC_PROGRAME,button,1342242816
Control18=IDC_UP_QUESTION,button,1342242816
Control19=IDC_DOWN_QUESTION,button,1342242816
Control20=IDC_CONFIRE,button,1342242816
Control21=IDC_COMMIT_PAPER,button,1342242816

[DLG:IDD_PROGRAME]
Type=1
Class=CProgramDialog
ControlCount=4
Control1=IDC_STATIC_ANSWER,static,1342177280
Control2=IDC_RICHEDIT1,RICHEDIT,1352728580
Control3=IDC_SAVE,button,1342242816
Control4=IDC_CANCLE,button,1342242816

[CLS:CMainInformation]
Type=0
HeaderFile=MainInformation.h
ImplementationFile=MainInformation.cpp
BaseClass=CDialog
Filter=D
LastObject=CMainInformation

[CLS:CMyInformation]
Type=0
HeaderFile=MyInformation.h
ImplementationFile=MyInformation.cpp
BaseClass=CDialog
Filter=D
LastObject=CMyInformation

[CLS:CProgramDialog]
Type=0
HeaderFile=ProgramDialog.h
ImplementationFile=ProgramDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CProgramDialog

[CLS:CExamination]
Type=0
HeaderFile=Examination.h
ImplementationFile=Examination.cpp
BaseClass=CDialog
Filter=D
LastObject=CExamination

