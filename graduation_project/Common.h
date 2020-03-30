#ifndef _COMMON_H
#define _COMMON_H
#include "topic.h"
extern CTime examtime;  //获取考试 时间
extern CTime exam_longtime; //获取考试 时长
extern int score;           //表示当前得分
int singleChoice(int index); //单选
int mutileChoice(int index); //多选
int gapFilling(int index);   //填空
int isTrue(int index);       //判断题
int program(int index);      //编程题
CTimeSpan CstringtoCtimespan(const CString str);
CTime CStringtoCtime(const CString str);
#endif