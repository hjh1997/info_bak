#include<iostream.h>
#include"stl_alloc.h"
#define _USE_MALLOC //定义使用一级配置器

#ifdef _USE_MALLOC
typedef _malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;
#else
typedef __default_alloc_template<0,0> alloc;
#endif

void out_of_memroy()  //回调方法只是简单的打印，如果不安装处理函数，就直接抛出异常
{
	cout<<"Out of memroy"<<endl;
	exit(1);
}
void main()
{
	_malloc_alloc_template<0>::set_malloc_handler(out_of_memroy);//装载处理函数，处理当申请不成功时的处理方法
	//int *p =(int*)_malloc_alloc_template<0>::allocate(sizeof(int)*4);使用一级空间配置器
	//int *ptr = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*100); //使用二级空间配置值
	simple_alloc<int,alloc> it; //调用一级二级配置器接口
	it.allocate(200);
}
