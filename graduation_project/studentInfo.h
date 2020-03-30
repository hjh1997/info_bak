#ifndef __STUDENTINFO_H
#define __STUDENTINFO_H

#include "Common.h"

class Student
{
public:
	Stuent(char *number=NULL,char *password=NULL,char *name=NULL,char *class_= NULL,\
char *professtion=NULL,char *academy=NULL,char *phone=NULL,char*score=NULL);
	void Set_info(char *number=NULL,char *password=NULL,char *name=NULL,char *class_= NULL,\
char *professtion=NULL,char *academy=NULL,char *phone=NULL,char*score=NULL);
public:
	static char stu_number[20];
	static char stu_password[20];
	static char stu_name[30];
	static char stu_class[30];
	static char stu_professtion[50];
	static char stu_academy[30];
	static char stu_phone[20];
	static char stu_score[10];
};
extern Student student;
#endif