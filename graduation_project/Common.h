#ifndef _COMMON_H
#define _COMMON_H
#include "topic.h"
extern CTime examtime;  //��ȡ���� ʱ��  
extern CTime exam_longtime; //��ȡ���� ʱ�� ���ڼ��㵹��ʱ
extern CString exam_long;  //��ȡ����ʱ��
extern float score;           //��ʾ��ǰ�÷�
extern float choice;
extern float istrue;
extern float gapfill;
extern float programe;
extern int choice_n;
extern int istrue_n;
extern int gapfill_n;
extern int programe_n;
extern float choice_p;
extern float istrue_p;
extern float gapfill_p;
extern float programe_p;
extern bool is_finished;
float singleChoice(int index); //��ѡ
float mutileChoice(int index); //��ѡ
float gapFilling(int index);   //���
float isTrue(int index);       //�ж���
float program(int index);      //�����
int my_strlen(char *str);       //���� ����� //�� ','��β ����'\0'��β
int strsub(char *des,char * sor); //Ѱ���Ӵ�
int my_strcmp(char * str1,char *str2);  //�Ƚ������ַ���

float calculate();
CTimeSpan CstringtoCtimespan(const CString str);
CTime CStringtoCtime(const CString str);
#endif