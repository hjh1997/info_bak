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
		  AfxMessageBox("���ݿ�����ʧ��");
		  return 0;	
	}
	//mydbΪ�������������ݿ⣬3306Ϊ�˿ںţ�root���û���,dxd������
	AfxMessageBox("���ݿ����ӳɹ�");
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
	
	if(0!=mysql_options(&mysql,MYSQL_SET_CHARSET_NAME,"gb2312")) //���ݿ�����ѡ�������ת��
    { 
		mysql_close(&mysql);
		mysql_library_end();
        return -1; 
    }

	if(!mysql_real_connect(&mysql,"localhost","root","123456","mydb",3306,NULL,0))
	{        //mydbΪ�������������ݿ⣬3306Ϊ�˿ںţ�root���û���,dxd������

		mysql_close(&mysql);
		mysql_library_end();
		AfxMessageBox("���ݿ�����ʧ��");
		return -1;
	}
	AfxMessageBox("���ݿ����ӳɹ�");
	return 1;
}

int Query(char * str)
{
	if (0 == mysql_query(&mysql,str)) //ִ����ȷ
	{
		//cout<<"mysql_query select succeed"<<endl;
		result=mysql_store_result(&mysql); //��ȡ�����result
		/*int rowcount=mysql_num_rows(result);  //��ȡ���ؽ��������
		cout<<"row count:"<<rowcount<<endl;
		unsigned int fieldcount=mysql_num_fields(result); //��ȡ�еĸ���
		MYSQL_FIELD *field=NULL;  //field �����ֶ������ʹ�С��
        for(unsigned int i=0;i<fieldcount;i++) 
        { 
			field=mysql_fetch_field_direct(result,i); 
            cout<<field->name<<"\t\t"; 
        }
		*/
		AfxMessageBox("��ѯ�ɹ�");
		return 1;
	}
	AfxMessageBox("��ѯʧ��");
	return 0;
}