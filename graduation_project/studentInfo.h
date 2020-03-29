#ifndef __STUDENTINFO_H
#define __STUDENTINFO_H

#include "Common.h"

class Student
{
public:
	Stuent(char *number=NULL,char *password=NULL,char *name=NULL,char *class_= NULL,\
char *professtion=NULL,char *academy=NULL,char *phone=NULL,char*score=NULL);
private:
	static char stu_number[20];
	static char stu_password[20];
	static char stu_name[30];
	static char stu_class[30];
	static char stu_professtion[30];
	static char stu_academy[30];
	static char stu_phone[20];
	static char stu_score[10];
};
char Student::stu_number[20]={'0'};
char Student::stu_password[20]={'0'};
char Student::stu_name[30]={'0'};
char Student::stu_class[30]={'0'};
char Student::stu_professtion[30]={'0'};
char Student::stu_academy[30]={'0'};
char Student::stu_phone[20]={'0'};
char Student::stu_score[10]={'0'};

Student::Stuent(char *number,char *password,char *name,char *class_,\
char *professtion,char *academy,char *phone,char*score)
{
	if(NULL != number)
		strcpy(stu_number,number);
	if(NULL != password)
		strcpy(stu_password,password);
	if(NULL != password)
		strcpy(stu_name,name);
	if(NULL != password)
		strcpy(stu_class,class_);
	if(NULL != password)
		strcpy(stu_professtion,professtion);
	if(NULL != password)
		strcpy(stu_academy,academy);
	if(NULL != password)
		strcpy(stu_phone,phone);
	if(NULL != password)
		strcpy(stu_score,score);
}

extern Student student;
#endif