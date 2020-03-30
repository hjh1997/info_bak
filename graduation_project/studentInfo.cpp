#include "stdafx.h"
#include "studentInfo.h"
char Student::stu_number[20]={'0'};
char Student::stu_password[20]={'0'};
char Student::stu_name[30]={'0'};
char Student::stu_class[30]={'0'};
char Student::stu_professtion[50]={'0'};
char Student::stu_academy[30]={'0'};
char Student::stu_phone[20]={'0'};
char Student::stu_score[10]={'0'};
void Student::Set_info(char *number,char *password,char *name,char *class_,\
char *professtion,char *academy,char *phone,char*score)
{
	if(NULL != number)
		strcpy(stu_number,number);
	if(NULL != password)
		strcpy(stu_password,password);
	if(NULL != name)
		strcpy(stu_name,name);
	if(NULL != class_)
		strcpy(stu_class,class_);
	if(NULL != professtion)
		strcpy(stu_professtion,professtion);
	if(NULL != academy)
		strcpy(stu_academy,academy);
	if(NULL != phone)
		strcpy(stu_phone,phone);
	if(NULL != score)
		strcpy(stu_score,score);
}
Student::Stuent(char *number,char *password,char *name,char *class_,\
char *professtion,char *academy,char *phone,char*score)
{
	if(NULL != number)
		strcpy(stu_number,number);
	if(NULL != password)
		strcpy(stu_password,password);
	if(NULL != name)
		strcpy(stu_name,name);
	if(NULL != class_)
		strcpy(stu_class,class_);
	if(NULL != professtion)
		strcpy(stu_professtion,professtion);
	if(NULL != academy)
		strcpy(stu_academy,academy);
	if(NULL != phone)
		strcpy(stu_phone,phone);
	if(NULL != score)
		strcpy(stu_score,score);
}