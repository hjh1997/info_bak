#ifndef __TOPIC_H
#define __TOPIC_H

#include<iostream>
#include<vector>
using namespace std;
extern  vector<char*> answer;      //�û����������
class Exam_question
{
public:
	Exam_question(){ use_count++;}
	void e_push_back( char*ptr);
	int  e_size()const;
	int  e_capacity()const;
	int  e_getusecount()const{ return use_count;}
	int  e_get_current()const{ return current; }
	void e_reserver(int capacity); //�����������������������й��̽�������
	char* e_set_point(int index); //��ȡָ��λ����Ŀ ��[]������ͬ��������������current
	char*& operator[](const int n)const;
	char*& operator++(); //++i
	char*& operator--(); //--i    //���صĶ���ָ����Ŀ��ָ��
public:
	~Exam_question()
	{
		use_count--;
		//cout<<"count��һ"<<endl;
		if(0 == use_count)
		{
			int i;
			//cout<<"��Ŀ��Ϣ���ж�������"<<endl;
			for(i=0;i<e_size();i++)
			{
				delete [] str[i];
				if(NULL != answer[i])
					delete [] answer[i];
			}
		}
	}
private:
	static int use_count;        //��ʾ���ô˶���ĸ���
	static vector<char*> str;    //���ڱ�����Ŀ
	static int current;          //����ָ��ǰ���λ��
};

class question_info  //��������Ŀ����±������Ϣһһ��Ӧ
{
public:
	question_info(){use_count++;}
	void Push_back(int id,int type,float score,char *ptr);
	int getsize()const
	{
		return answer.size();
	}
	int get_id(const int index)const{return id[index];}
	int get_type(const int index)const{return type[index];}
	/*void print()
	{
		vector<int>::iterator it = id.begin();
		for(it;it!=id.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
		it = type.begin();
		for(it;it!=type.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
		it = score.begin();
		for(it;it!=score.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
		vector<char* >::iterator it1 = answer.begin();
		for(it1;it1!=answer.end();it1++)
		{
			cout<<*it1<<" ";
		}
	}*/

public:
	~question_info()
	{
		use_count--;
		if(0 == use_count)
		{
			int i;
			//cout<<"��Ŀ��Ϣ���������"<<endl;
			for(i=0;i<getsize();i++)
			{
				delete [] answer[i];
			}
		}
	}
public:
	static vector<int> id;
	static vector<int> type;
    static vector<float> score;
	static vector<char*> answer; 
	static int use_count;
};

extern  Exam_question exam_ques;
extern  question_info exam_info;
#endif