#ifndef COMMON_H
#define COMMON_H

extern CTime examtime;  //获取考试 时间
extern CTime exam_longtime; //获取考试 时长

CTimeSpan CstringtoCtimespan(const CString str);
CTime CStringtoCtime(const CString str);
#endif