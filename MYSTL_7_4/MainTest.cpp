#include<iostream.h>
#include"stl_alloc.h"
#define _USE_MALLOC //����ʹ��һ��������

#ifdef _USE_MALLOC
typedef _malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;
#else
typedef __default_alloc_template<0,0> alloc;
#endif

void out_of_memroy()  //�ص�����ֻ�Ǽ򵥵Ĵ�ӡ���������װ����������ֱ���׳��쳣
{
	cout<<"Out of memroy"<<endl;
	exit(1);
}
void main()
{
	_malloc_alloc_template<0>::set_malloc_handler(out_of_memroy);//װ�ش��������������벻�ɹ�ʱ�Ĵ�����
	//int *p =(int*)_malloc_alloc_template<0>::allocate(sizeof(int)*4);ʹ��һ���ռ�������
	//int *ptr = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*100); //ʹ�ö����ռ�����ֵ
	simple_alloc<int,alloc> it; //����һ�������������ӿ�
	it.allocate(200);
}
