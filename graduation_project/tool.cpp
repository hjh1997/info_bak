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