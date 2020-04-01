#ifndef _COMMON_H
#define _COMMON_H
#include "topic.h"
extern CTime examtime;  //获取考试 时间  
extern CTime exam_longtime; //获取考试 时长 用于计算倒计时
extern CString exam_long;  //获取考试时长
extern float score;           //表示当前得分
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
float singleChoice(int index); //单选
float mutileChoice(int index); //多选
float gapFilling(int index);   //填空
float isTrue(int index);       //判断题
float program(int index);      //编程题
int my_strlen(char *str);       //辅助 填空题 //以 ','结尾 或者'\0'结尾
int strsub(char *des,char * sor); //寻找子串
int my_strcmp(char * str1,char *str2);  //比较两个字符串

float calculate();
CTimeSpan CstringtoCtimespan(const CString str);
CTime CStringtoCtime(const CString str);
#endif