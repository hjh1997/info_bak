#ifndef __STL_ALLOC_
#define __STL_ALLOC_

#if 0
#include<new>
#define _THROW_BAD_ALLOC throw bad_alloc;
#elif !defined(_THROW_BAD_ALLOC)
#include<iostream.h>
#include<malloc.h>
#include<stdlib.h>
#define __THROW_BAD_ALLOC cerr<<"out of memory."<<endl; exit(1);
#endif
template<int inst>
class _malloc_alloc_template   //模拟set_new_handler机制处理申请空间出错问题 这是一级空间配置器,大于128调动
{
public:
	static void* allocate(size_t n)
	{
		void *result = malloc(n);
		if(result == 0)
			result = oom_malloc(n); //out of memory
		return result;
	}
	static void  deallocate(void *p,size_t n)
	{
		free(p);
	}
	static void reallocate(void *p,size_t old_sz,size_t new_sz)
	{
		void *result = realloc(p,new_sz);
		if(resilt == 0)
			result = oom_realloc(p,new_sz); //out of memory
		return result;
	}
	static void (*set_malloc_handler(void(*f)()))()
	{
		void (*old)()= _malloc_alloc_oomhandler;
		_malloc_alloc_oomhandler = f;
		return *old;
	}
private:
	static void *oom_malloc(size_t n);
	static void *oom_realloc(void *p,size_t sz);
	static void (*_malloc_alloc_oomhandler)();  //函数指针
};
template<int inst>
void (*_malloc_alloc_template<inst>::_malloc_alloc_oomhandler)()=0;
template<int inst>
void *_malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void (*my_malloc_handler)();
	void *result;
	for(;;)
	{
		my_malloc_handler = _malloc_alloc_oomhandler; //等待用户设置处理函数 set_new_handler
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}
		(*my_malloc_handler)();
		result = malloc(n);
		if(result)
			return result;
	}
}
template<int inst>
void *_malloc_alloc_template<inst>::oom_realloc(void *p,size_t n)
{
	void (*my_malloc_handler)();
	void *result;
	for(;;)
	{
		my_malloc_handler = _malloc_alloc_oomhandler; //等待用户设置处理函数 set_new_handler
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}
		(*my_malloc_handler)();
		result = realloc(n);
		if(result)
			return result;
	}
}
///////////////////////////////////////////////////////////

typedef _malloc_alloc_template<0> malloc_alloc;


enum{__ALIGN = 8};
enum{__MAX_BYTES=128};
enum{__NFREELISTS =__MAX_BYTES / __ALIGN}; //free-list个数

template<bool threads,int inst>
class __default_alloc_template
{
private:
	static size_t ROUND_UP(size_t bytes)
	{
		return (((bytes)+__ALIGN-1)&~(__ALIGN-1));
	}
	static size_t FREELIST_INDEX(size_t bytes)
	{
		return (((bytes)+__ALIGN-1) / __ALIGN-1);
	}
private:
	union obj //free_list 节点构造
	{
		union obj *free_list_link;
		char client_data[1];
	};
	static void *refill(size_t n);
	static char* chunk_alloc(size_t size,int &nobj);
	static obj *free_list[__NFREELISTS];
private:
	static char *start_free; 
	static char *end_free;
	static size_t heap_size;
public:
	static void *allocate(size_t n);
	static void deallocate(void *p,size_t n);
	static void *reallocate(void *p,size_t old_sz,size_t new_sz);
};
template<bool threads,int inst>
char *__default_alloc_template<threads,inst>::start_free = 0;
template<bool threads,int inst>
char *__default_alloc_template<threads,inst>::end_free = 0;
template<bool threads,int inst>
size_t __default_alloc_template<threads,inst>::heap_size = 0;
template<bool threads,int inst>
__default_alloc_template<threads,inst>::obj*__default_alloc_template<threads,inst>::free_list[__NFREELISTS]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

template<bool threads,int inst>
void *__default_alloc_template<threads,inst>::allocate(size_t n)
{
	obj ** my_free_list;
	obj *result;
	if(n > (size_t)__MAX_BYTES)
	{
		cout<<"调用一级空间配置器"<<endl;
		return (malloc_alloc::allocate(n));
	}
	my_free_list = free_list+FREELIST_INDEX(n);
	result = *my_free_list;
	if(NULL == result)
	{
		void *r = refill(ROUND_UP(n));
		return r;
	}
	*my_free_list = result->free_list_link;
	return result;
}
template<bool threads,int inst>
void __default_alloc_template<threads,inst>::deallocate(void *p,size_t n)
{
	obj *q = (obj*)p;
	obj **my_free_list;
	if(n > __MAX_BYTES)
	{
		malloc_alloc::deallocate(p,n);
		return;
	}
	my_free_list = free_list+FREELIST_INDEX(n); //头插
	q->free_list_link = *my_free_list;
	*my_free_list = q;
}
template<bool threads,int inst>
char* __default_alloc_template<threads,inst>::chunk_alloc(size_t size,int &nobjs)
{
	char *result;
	size_t total_size = size *nobjs;
	size_t bytes_left = end_free - start_free; //内存池剩余空间
	if(bytes_left >=total_size) //完全够分配
	{
		result = start_free;
		start_free += total_size;
		return result;
	}
	else if(bytes_left >=total_size)  //只够分配一个或多个。不够size个
	{
		nobjs = bytes_left /size;
		total_size = size*nobjs;
		result = start_free;
		start_free +=total_size;
		return result;
	}
	else   //内存池一个都不能分配
	{
		size_t  bytes_to_get = 2*total_size+ROUND_UP(heap_size>>4);
		//回收零头
		if(bytes_left >0)
		{
			obj **my_free_list;
			my_free_list = free_list+FREELIST_INDEX(bytes_left);
			//头插
			((obj*)start_free)->free_list_link = *my_free_list;
			*my_free_list = (obj*)start_free;
		}
		start_free = (char*)malloc(bytes_to_get);  //向内存申请空间
		if(0 == start_free)
		{
			int i;
			obj **my_free_list,*p;
			for( i =size;i<__MAX_BYTES;i+=__ALIGN)
			{
				my_free_list = free_list+FREELIST_INDEX(i);
				p = *my_free_list;
				if(0 != p)
				{
					*my_free_list = p->free_list_link;
					start_free = (char*)p;
					end_free = start_free+i;
					return (chunk_alloc(size,nobjs));
				}
			}
			end_free = 0;
			start_free = (char*)malloc_alloc::allocate(bytes_to_get);
		}
		heap_size +=bytes_to_get;
		end_free = start_free+bytes_to_get;
		return chunk_alloc(size,nobjs);
	}
}
template<bool threads,int inst>
void *__default_alloc_template<threads,inst>::refill(size_t n)
{
	int nobjs =20;
	//调用chunk_alloc尝试取得nobjs区块作为free_list的新节点
	char *chunk = chunk_alloc(n,nobjs);
	obj **my_free_list;
	obj *result;
	obj *current_obj,*next_obj;
	int i;
	
	if(1 == nobjs)
		return chunk;
	my_free_list = free_list+FREELIST_INDEX(n);
	result = (obj*)chunk;
	*my_free_list =next_obj=(obj*)(chunk+n);
	for(i=1;;++i) // 进行分块
	{
		current_obj = next_obj;
		next_obj =(obj*)((char*)next_obj+n);
		if(nobjs -1 == i)
		{
			current_obj->free_list_link = 0;
			break;
		}
		else
		{
			current_obj->free_list_link = next_obj;
		}
	}
	return result;
}
////////////////////////////////////////////////////////////////
template<class T,class Alloc>
class simple_alloc
{
public:
	static T *allocate(size_t n)
	{
		return (0 == n)?0:(T*)Alloc::allocate(n*sizeof(T));
	}
	static T *allocate(void)
	{
		return (T*)Alloc::allocate(sizeof(T));
	}
	static void deallocate(T *p,size_t n)
	{
		if(0 != n)
			Alloc::deallocate(p,n*sizeof(T));
	}
	static void deallocate(T *p)
	{
		Alloc::deallocate(p,sizeof(T));
	}
};
#endif