#ifndef _CONNECTMYSQL_H
#define _CONNECTMYSQL_H

#include "winsock.h"

extern MYSQL mysql; //数据库连接句柄 声明为全局变量
extern MYSQL_RES *result; //数据库返回结果集
int ConnectSql();   //初始化mysql库，连接句柄，以及连接数据库
int Query(char *str); //执行mysql_query 语句。存放到MYSQL_RES 结构体中

#endif