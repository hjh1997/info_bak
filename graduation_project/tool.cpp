#include "stdafx.h"
#include "common.h"
float score=0;           //��ʾ��ǰ�÷�
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
	exam_long.Format("��������ʱ��:%dʱ%d�֡�����ǰ����׼��!",dhour,dminute);
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
int strsub(char *des,char * sor) //Ѱ���Ӵ�
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
int my_strcmp(char * str1,char *str2)  //�Ƚ������ַ���
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
float singleChoice(int index) //��ѡ
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
float mutileChoice(int index) //��ѡ  
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
		if(*tmp == '\0') //˵����ѡ��δƥ�䵽
			break;
		p++;
	}
	if(*p != '\0') //��δƥ�䵽��ѡ��
		return 0;
	return exam_info.score[index];
}
float gapFilling(int index)   //��� ��ֻ��Ҫ���ؼ���
{
	char *p = answer[index];
	if(p == NULL)
		return 0;
	char *p_s = exam_info.answer[index];
	//����Ƕ������⣬��������ŷָ�������д���ѡ��Ӣ�İ�Ƕ���,��¼��ͬ����ʽ����
	//�жϴ��Ǻ��ֻ���������ĸ �������������ĸֱ�Ӿ�ȷƥ�䣬����Ǻ��������ģ��ƥ��
	int count = 0;
	while(*p_s != '\0') //�����м����� 0---1  1 ---2 
	{
		if(*p_s == ',')
			count++;
		p_s++;
	}
	while(*p!='\0') //ת��Ϊ��Ƿ���
	{
		if((*(short*)(p)) == 0xffffaca3)  //ȫ�Ƿ��� 0xffffaca3Ϊȫ�Ƿ���'��'��ʮ�����Ʊ�ʾ
		{
			*p++=',';
			char *tmp = p;
			char *tnext = tmp;
			while(*tmp != '\0')  // abc,fedd'\0'
			{                    //abc,��
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
	int currct = 0;    //���������ȷ����
	int res = 0;
	while(*p_s != '\0')//���δ�����ǶԱȵĵ�һ��
	{
		if(*p_s <0) //ģ��ƥ��
		{
			res =strsub(p,p_s);
		}
		else
		{
			res = my_strcmp(p,p_s);    //��ȷƥ��
			if(res == -1)
				AfxMessageBox("��ȷƥ��ʧ��");
			else 
				AfxMessageBox("��ȷƥ��ɹ�");
		}
		while(*p_s!=',' && *p_s!='\0')
			p_s++;
		if(*p_s == ',') //ֱ���ҵ�.
		{
			p_s++;
		}
		if(res == 1)
			currct++;
		if(*p_s == '\0') //����
			break;
		while(*p!=',' && *p!='\0')
			p++;
		if(*p == ',') //ֱ���ҵ�.
		{
			p++;
		}
	}
	CString s;
	s.Format("���� %d�� ����У�%d",count+1,currct);
	AfxMessageBox(s);
	return((exam_info.score[index]/(count+1)) *currct);
}
float isTrue(int index)       //�ж���
{
	if(answer[index] == NULL)
		return 0;
	if(*answer[index] == toupper(*exam_info.answer[index])) // �ж�AB
		return exam_info.score[index];
	return 0;
}
float program(int index)      //�����
{
	return 0;
}

float calculate()
{
	int type;
	int i=0;
	AfxMessageBox("���ڼ���");
	/*extern float score;           //��ʾ��ǰ�÷�
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
	_p������ʾ ������Ŀ����ȷ�÷֣��޽�����ʾ ������Ŀ���ܷ�
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
			choice_p+=res;  //����ѡ�����͵ĵ÷�
			choice+=exam_info.score[i]; //����ѡ�����ܷ�
			choice_n++;  //����ѡ����ĸ���
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
	AfxMessageBox("�������");
	return score;
}
/*	�ڶ��ְ취
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