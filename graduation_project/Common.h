#ifndef COMMON_H
#define COMMON_H

extern CTime examtime;  //��ȡ���� ʱ��
extern CTime exam_longtime; //��ȡ���� ʱ��

CTimeSpan CstringtoCtimespan(const CString str);
CTime CStringtoCtime(const CString str);
#endif