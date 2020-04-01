#include "stdafx.h"
#include "topic.h"

vector<char*> Exam_question::str;
int Exam_question::use_count = 0;
int Exam_question::current = -1;

int question_info::use_count = 0;
vector<int> question_info::id;
vector<int> question_info::type;
vector<float> question_info::score;
vector<char*> question_info::answer;
char*&Exam_question::operator [](const int n)const
{
	return str[n];
}
char*&Exam_question::operator ++()
{
	++current;
	if(current >= e_size())
	{
		current = 0;
		return str[current];
	}
	return str[current];
}
char*&Exam_question::operator --()
{
	--current;
	if(current < 0 )
	{
		current = e_size()-1;
		return str[current];
	}
	return str[current];
}
char*Exam_question::e_set_point(int index)
{
	if (index >= e_size())
		return NULL;
	else
	{
		current = index;
		return str[current];
	}
}
void Exam_question::e_push_back( char*ptr)
{
	if(NULL != ptr)
		str.push_back(ptr);
	if(-1 == current)
		current = 0;
}
int Exam_question::e_size()const
{
	return str.size();
}
int Exam_question::e_capacity()const
{
	return str.capacity();
}
void Exam_question::e_reserver(int cap)
{
	str.reserve(cap);
}

////////////////////////////////////////////

void question_info::Push_back(int id_,int type_,float score_,char *ptr_)
{
	id.push_back(id_);
	type.push_back(type_);
	score.push_back(score_);
	answer.push_back(ptr_);
}