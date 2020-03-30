#include "stdafx.h"
#include "common.h"

CTimeSpan CstringtoCtimespan(const CString res1)
{
	CString hour = res1.Left(res1.Find(':'));
	CString minute = res1.Mid(res1.Find(':')+1,res1.ReverseFind(':')-res1.Find(':')-1);
	CString second = res1.Right(res1.GetLength() - res1.ReverseFind(':')-1);
	char *hourstr = (char*)(LPCTSTR)hour;
	char *minutestr = (char*)(LPCTSTR)minute;
	char *secondstr = (char*)(LPCTSTR)second;
	int dhour = atoi(hourstr);
	int dminute = atoi(minutestr);
	int dsecond = atoi(secondstr);
	CTimeSpan span(0,dhour,dminute,dsecond);
	return span;
}

CTime CStringtoCtime(const CString res)
{
	COleVariant vtime(res);
	vtime.ChangeType(VT_DATE);
	COleDateTime cOleTime=vtime;
	SYSTEMTIME systime;
	VariantTimeToSystemTime(cOleTime, &systime);
	CTime cTimeFromDB(systime);
	return cTimeFromDB;
}
int singleChoice(int index) //单选
{
	if(stricmp(answer[index],exam_info.answer[index]))
		return exam_info.score[index];
	return 0;
}
int mutileChoice(int index) //多选  
{
	char *p = answer[index];
	while(*p != '\0')
	{
		char *tmp = exam_info.answer[index];
		while(*tmp != '\0')
		{
			if(*p != toupper(*tmp))
				tmp++;
			if(*p == toupper(*tmp))
				break;
		}
		if(*tmp == '\0') //说明有选项未匹配到
			break;
		p++;
	}
	if(*p != '\0') //有未匹配到的选项
		return 0;
	return exam_info.score[index];
}
int gapFilling(int index)   //填空
{

	return 0;
}
int isTrue(int index)       //判断题
{
	if(stricmp(answer[index],exam_info.answer[index])) // 判断AB
		return exam_info.score[index];
	return 0;
}
int program(int index)      //编程题
{
	return 0;
}


/*	第二种办法
	COleVariant vtime(res);
	vtime.ChangeType(VT_DATE);
	COleDateTime cOleTime=vtime;
	SYSTEMTIME systime;
	VariantTimeToSystemTime(cOleTime, &systime);
	CTime cTimeFromDB(systime);
	examtime = cTimeFromDB;
	CMainInformation mainframe;
	mainframe.DoModal();
/*	CString year,month,day,hour,minute,second;
	year = lstr.Left(lstr.Find('-'));
	month = lstr.Mid(lstr.Find('-')+1,lstr.ReverseFind('-')-lstr.Find('-')-1);
	day = lstr.Right(lstr.GetLength() - lstr.ReverseFind('-')-1);
//	AfxMessageBox(year);
//	AfxMessageBox(month);
//	AfxMessageBox(day);
	hour = rstr.Left(rstr.Find(':'));
	minute = rstr.Mid(rstr.Find(':')+1,rstr.ReverseFind(':')-rstr.Find(':')-1);
	second = rstr.Right(rstr.GetLength() - rstr.ReverseFind(':')-1);
//	AfxMessageBox(hour);
//	AfxMessageBox(minute);
//	AfxMessageBox(second);
	char *yearstr = (char*)(LPCTSTR)year;
	char *monthstr = (char*)(LPCTSTR)month;
	char *daystr = (char*)(LPCTSTR)day;
	char *hourstr = (char*)(LPCTSTR)hour;
	char *minutestr = (char*)(LPCTSTR)minute;
	char *secondstr = (char*)(LPCTSTR)second;
	int dyear = atoi(yearstr);
	int dmonth = atoi(monthstr);
	int dday = atoi(daystr);
	int dhour = atoi(hourstr);
	int dminute = atoi(minutestr);
	int dsecond = atoi(secondstr);
	CTime time(dyear,dmonth,dday,dhour,dminute,dsecond);
	examtime = time;
*/