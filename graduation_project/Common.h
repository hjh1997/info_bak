#ifndef _COMMON_H
#define _COMMON_H
#include "topic.h"
extern CTime examtime;  //��ȡ���� ʱ��
extern CTime exam_longtime; //��ȡ���� ʱ��
extern int score;           //��ʾ��ǰ�÷�
int singleChoice(int index); //��ѡ
int mutileChoice(int index); //��ѡ
int gapFilling(int index);   //���
int isTrue(int index);       //�ж���
int program(int index);      //�����
CTimeSpan CstringtoCtimespan(const CString str);
CTime CStringtoCtime(const CString str);
#endif