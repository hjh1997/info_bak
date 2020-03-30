; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyInformation
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "graduation project.h"

ClassCount=8
Class1=CGraduationprojectApp
Class2=CGraduationprojectDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_SCORE
Resource2=IDR_MAINFRAME
Resource3=IDD_PROGRAME
Resource4=IDD_MAIN_INTERFACE
Resource5=IDD_EXAMINATION
Resource6=IDD_MY_INFOMATION
Resource7=IDD_GRADUATIONPROJECT_DIALOG
Class4=CMainInformation
Class5=CMyInformation
Class6=CProgramDialog
Class7=CExamination
Resource8=IDD_ABOUTBOX
Class8=CMy_Score
Resource9=IDR_MENU1

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
ControlCount=12
Control1=IDC_START_EXAM,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_HOUR,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_MINUTE,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SECOND,edit,1350631552
Control8=IDC_DAY,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CANCLE,button,1342242816
Control12=IDC_STATIC1,static,1342308353

[MNU:IDR_MENU1]
Type=1
Class=CMainInformation
Command1=ID_MENU_INFO
Command2=ID_MENU_SCORE
Command3=ID_MENU_HELP
CommandCount=3

[DLG:IDD_MY_INFOMATION]
Type=1
Class=CMyInformation
ControlCount=13
Control1=IDC_STATIC_ID,static,1342308352
Control2=IDC_STATIC_NAME,static,1342308352
Control3=IDC_STATIC_CLASS,static,1342308352
Control4=IDC_STATIC_PHONE,static,1342177280
Control5=IDC_STATIC_MAJOR,static,1342308352
Control6=IDC_STU_ID,edit,1350633600
Control7=IDC_NAME,edit,1350633600
Control8=IDC_CLASS,edit,1350633600
Control9=IDC_PHONE,edit,1350639744
Control10=IDC_MAJOR,combobox,1344339970
Control11=IDC_STATIC,static,1342308352
Control12=IDC_CHANGE,button,1342242816
Control13=IDC_CLOSE,button,1342242816

[DLG:IDD_EXAMINATION]
Type=1
Class=CExamination
ControlCount=28
Control1=IDC_STATIC_QUESTION,button,1342177287
Control2=IDC_STATIC_STATE,button,1342177287
Control3=IDC_LIST,SysListView32,1350631429
Control4=IDC_STATIC_ANSWER,button,1342177287
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_PROGRAME,button,1342242816
Control7=IDC_UP_QUESTION,button,1342242816
Control8=IDC_DOWN_QUESTION,button,1342242816
Control9=IDC_CONFIRE,button,1342242816
Control10=IDC_COMMIT_PAPER,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_HOUR,edit,1476460673
Control13=IDC_MINUTE,edit,1476460673
Control14=IDC_SECOND,edit,1476460673
Control15=IDC_STATIC,static,1342308353
Control16=IDC_STATIC,static,1342308353
Control17=IDC_QUESTION,edit,1344340036
Control18=IDC_CHECK1,button,1342373891
Control19=IDC_CHECK2,button,1342242819
Control20=IDC_CHECK3,button,1342242819
Control21=IDC_CHECK4,button,1342242819
Control22=IDC_RADIO1,button,1342308361
Control23=IDC_RADIO2,button,1342177289
Control24=IDC_RADIO3,button,1342177289
Control25=IDC_RADIO4,button,1342177289
Control26=IDC_STATIC,static,1342177280
Control27=IDC_STATIC1,static,1342177280
Control28=IDC_STATIC2,static,1342308352

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
VirtualFilter=dWC

[CLS:CMyInformation]
Type=0
HeaderFile=MyInformation.h
ImplementationFile=MyInformation.cpp
BaseClass=CDialog
Filter=D
LastObject=CMyInformation
VirtualFilter=dWC

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
LastObject=IDC_CHECK3
VirtualFilter=dWC

[DLG:IDD_SCORE]
Type=1
Class=CMy_Score
ControlCount=4
Control1=IDC_STATIC1,static,1342177280
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_SURE,button,1342242816
Control4=IDC_CANCLE,button,1342242816

[CLS:CMy_Score]
Type=0
HeaderFile=My_Score.h
ImplementationFile=My_Score.cpp
BaseClass=CDialog
Filter=D
LastObject=CMy_Score

