#include "stdafx.h"
#include "ConnectMysql.h"

MYSQL mysql;
MYSQL_RES *result = NULL;
int ConnectSql()
{
	/*MYSQL mysql;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql,"localhost","root","123456","mydb",3306,NULL,0))
	{        
		  AfxMessageBox("数据库连接失败");
		  return 0;	
	}
	//mydb为你所创建的数据库，3306为端口号，root是用户名,dxd是密码
	AfxMessageBox("数据库连接成功");
	*/

	if (0 != mysql_library_init(0,NULL,NULL))
	{
	    //cout<<"mysql_library_init failed"<<endl;
		return -3;
	}
	
	if (NULL == mysql_init(&mysql))
	{
		//cout<<"mysql_init failed"<<endl;
		mysql_library_end();
		return -2;
	}
	
	if(0!=mysql_options(&mysql,MYSQL_SET_CHARSET_NAME,"gb2312")) //数据库连接选项，将字体转换
    { 
		mysql_close(&mysql);
		mysql_library_end();
        return -1; 
    }

	if(!mysql_real_connect(&mysql,"localhost","root","123456","mydb",3306,NULL,0))
	{        //mydb为你所创建的数据库，3306为端口号，root是用户名,dxd是密码

		mysql_close(&mysql);
		mysql_library_end();
		AfxMessageBox("数据库连接失败");
		return -1;
	}
	AfxMessageBox("数据库连接成功");
	return 1;
}

int Query(char * str)
{
	if (0 == mysql_query(&mysql,str)) //执行正确
	{
		//cout<<"mysql_query select succeed"<<endl;
		result=mysql_store_result(&mysql); //获取到结果result
		/*int rowcount=mysql_num_rows(result);  //获取返回结果的行数
		cout<<"row count:"<<rowcount<<endl;
		unsigned int fieldcount=mysql_num_fields(result); //获取列的个数
		MYSQL_FIELD *field=NULL;  //field 包含字段名类型大小。
        for(unsigned int i=0;i<fieldcount;i++) 
        { 
			field=mysql_fetch_field_direct(result,i); 
            cout<<field->name<<"\t\t"; 
        }
		*/
		AfxMessageBox("查询成功");
		return 1;
	}
	AfxMessageBox("查询失败");
	return 0;
}