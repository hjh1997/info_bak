#ifndef _CONNECTMYSQL_H
#define _CONNECTMYSQL_H

#include "winsock.h"

extern MYSQL mysql; //���ݿ����Ӿ�� ����Ϊȫ�ֱ���
extern MYSQL_RES *result; //���ݿⷵ�ؽ����
int ConnectSql();   //��ʼ��mysql�⣬���Ӿ�����Լ��������ݿ�
int Query(char *str); //ִ��mysql_query ��䡣��ŵ�MYSQL_RES �ṹ����

#endif