#include "stdafx.h"
#include "common.h"
float score=0;           //表示当前得分
float choice=0;
float istrue=0;
float gapfill=0;
float programe=0;
int choice_n=0;
int istrue_n=0;
int gapfill_n=0;
int programe_n=0;
float choice_p=0;
float istrue_p=0;
float gapfill_p=0;
float programe_p=0;
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
	exam_long.Format("本场考试时长:%d时%d分。请提前做好准备!",dhour,dminute);
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
int my_strlen(char *str)
{
	char *p = str;
	while(*str!= '\0' && *str!=',')
		str++;
	return int(str-p);
}
int strsub(char *des,char * sor) //寻找子串
{
	int deslen = my_strlen(des);
	int sorlen = my_strlen(sor);
	if(deslen >= sorlen)
	{
		while(*des != '\0')
		{
			if (strncmp(des,sor,sorlen) == 0)
				return 1;
			else
			{
				if(*des < 0)
					++des;
				++des;
			}
		}
		return 0;
	}
	else
	{
		while(*sor != '\0')
		{
			if (strncmp(sor,des,deslen) == 0)
				return 1;
			else
			{
				if(*sor < 0)
					++sor;
				++sor;
			}
		}
	}
	return 0;
}
int my_strcmp(char * str1,char *str2)  //比较两个字符串
{
	char *my =str1;
	char *anwser = str2;
	while(*anwser != '\0' && *anwser != ',')
	{
		if(toupper(*anwser) == toupper(*my))
		{
			anwser++;
			my++;
		}
		else
		{
			return -1;
		}
	}
	if((*anwser == ',' && *my==',') || (*anwser == ',' && *my=='\0'))
		return 1;
	if(*anwser == '\0'&& *my=='\0')
		return 1;
	return -1;
}
float singleChoice(int index) //单选
{
	CString s1(answer[index]);
	AfxMessageBox(s1);
	CString s2(exam_info.answer[index]);
	AfxMessageBox(s2);
	if(answer[index] == NULL)
		return 0;
	if(*answer[index] == toupper(*exam_info.answer[index]))
		return exam_info.score[index];
	return 0;
}
float mutileChoice(int index) //多选  
{
	char *p = answer[index];
	if(p == NULL)
		return 0;
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
float gapFilling(int index)   //填空 答案只需要给关键字
{
	char *p = answer[index];
	if(p == NULL)
		return 0;
	char *p_s = exam_info.answer[index];
	//如果是多个填空题，用特殊符号分割出来进行处理。选择英文半角逗号,答案录入同样格式处理
	//判断答案是汉字或者数字字母 ，如果是数字字母直接精确匹配，如果是汉字则进行模糊匹配
	int count = 0;
	while(*p_s != '\0') //计算有几个答案 0---1  1 ---2 
	{
		if(*p_s == ',')
			count++;
		p_s++;
	}
	while(*p!='\0') //转换为半角符号
	{
		if((*(short*)(p)) == 0xffffaca3)  //全角符号 0xffffaca3为全角符号'，'的十六进制表示
		{
			*p++=',';
			char *tmp = p;
			char *tnext = tmp;
			while(*tmp != '\0')  // abc,fedd'\0'
			{                    //abc,，
				*tmp = *(++tnext);
				if(*tmp == '\0')
					break;
				tmp++;
			}
			continue;
		}
		p++;
	}
	p_s = exam_info.answer[index];
	p = answer[index];
	int currct = 0;    //保存计算正确个数
	int res = 0;
	while(*p_s != '\0')//传参传入的是对比的第一个
	{
		if(*p_s <0) //模糊匹配
		{
			res =strsub(p,p_s);
		}
		else
		{
			res = my_strcmp(p,p_s);    //精确匹配
			if(res == -1)
				AfxMessageBox("精确匹配失败");
			else 
				AfxMessageBox("精确匹配成功");
		}
		while(*p_s!=',' && *p_s!='\0')
			p_s++;
		if(*p_s == ',') //直到找到.
		{
			p_s++;
		}
		if(res == 1)
			currct++;
		if(*p_s == '\0') //结束
			break;
		while(*p!=',' && *p!='\0')
			p++;
		if(*p == ',') //直到找到.
		{
			p++;
		}
	}
	CString s;
	s.Format("答案有 %d； 答对有：%d",count+1,currct);
	AfxMessageBox(s);
	return((exam_info.score[index]/(count+1)) *currct);
}
float isTrue(int index)       //判断题
{
	if(answer[index] == NULL)
		return 0;
	if(*answer[index] == toupper(*exam_info.answer[index])) // 判断AB
		return exam_info.score[index];
	return 0;
}
float program(int index)      //编程题
{
	return 0;
}

float calculate()
{
	int type;
	int i=0;
	AfxMessageBox("正在计算");
	/*extern float score;           //表示当前得分
    extern float choice;
    extern float istrue;
    extern float gapfill;
    extern flat programe;
    extern int choice_n;
	extern int istrue_n;
	extern int gapfill_n;
	extern int programe_n;
	extern int choice_p;
	extern int istrue_p;
	extern int gapfill_p;
	extern int programe_p;
	_p结束表示 这类题目的正确得分，无结束表示 这类题目的总分
	*/
	int res;
	for(i;i<answer.size();i++)
	{
		type = exam_info.type[i];
		res = 0;
		switch(type)
		{
		case 1:
			res = singleChoice(i);
			score+=res;
			choice_p+=res;  //保存选择类型的得分
			choice+=exam_info.score[i]; //保存选择题总分
			choice_n++;  //保存选择题的个数
			break;
		case 2:
			res = isTrue(i);
			score+=res;
			istrue_p+=res;
			istrue+=exam_info.score[i];
			istrue_n++;
			break;
		case 3:
			res = gapFilling(i);
			score+=res;
			gapfill_p+=res;
			gapfill+=exam_info.score[i];
			gapfill_n++;
			break;
		case 4:
			res = mutileChoice(i);
			score+=res;
			choice_p+=res;
			choice+=exam_info.score[i];
			choice_n++;
			break;
		case 5:
			res = program(i);
			score+=res;
			programe_p+=res;
			programe+=exam_info.score[i];
			programe_n++;
			break;
		}
	}
	AfxMessageBox("计算完毕");
	return score;
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