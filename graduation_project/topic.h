#ifndef __TOPIC_H
#define __TOPIC_H

#include<iostream>
#include<vector>
using namespace std;
extern  vector<char*> answer;      //用户答题的内容
class Exam_question
{
public:
	Exam_question(){ use_count++;}
	void e_push_back( char*ptr);
	int  e_size()const;
	int  e_capacity()const;
	int  e_getusecount()const{ return use_count;}
	int  e_get_current()const{ return current; }
	void e_reserver(int capacity); //重新设置容量，避免在运行过程进行扩充
	char* e_set_point(int index); //获取指定位置题目 和[]作用相同，但是其重置了current
	char*& operator[](const int n)const;
	char*& operator++(); //++i
	char*& operator--(); //--i    //返回的都是指向题目的指针
public:
	~Exam_question()
	{
		use_count--;
		//cout<<"count减一"<<endl;
		if(0 == use_count)
		{
			int i;
			//cout<<"题目信息进行对象销毁"<<endl;
			for(i=0;i<e_size();i++)
			{
				delete [] str[i];
				if(NULL != answer[i])
					delete [] answer[i];
			}
		}
	}
private:
	static int use_count;        //表示引用此对象的个数
	static vector<char*> str;    //用于保存题目
	static int current;          //用于指向当前浏览位置
};

class question_info  //此类与类目类的下标序号信息一一对应
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
			//cout<<"题目信息类对象销毁"<<endl;
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