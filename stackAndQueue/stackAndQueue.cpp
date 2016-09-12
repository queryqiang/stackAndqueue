/*
  *master pointer when pointer is a argument of function
*/

#include<iostream>
using namespace std;
const  int stack_size = 10;
const int stack_increase_size = 15;
typedef struct stack{
   int stack_size;
   int *top;
   int *base;
}sNode,*psNode;
int initStack(psNode st)
{
	st->base = (int*)malloc(sizeof(int)*stack_size);
	if(NULL == st->base)
	{
	   cout<<"failed malloc memroy "<<endl;
	   exit(1);
	}
	st->top = st->base;
	st->stack_size = stack_size;
	return 1;
}
int pushStack(psNode st,int e)
{
	if(st->top-st->base > st->stack_size)
	{
		
		cout<<"stack overflow"<<endl;
		exit(1);                                                                                                                                                                                                                                                                                                                                                                                               
	}
	else
	{
		*(++st->top) = e;

	}
	return 1;
}
int popStack(psNode st)
{
	int e;
	if((st->top - st->base) >= 0)
	{
		e = *(st->top);
		st->top--;
	}
	else
	{
	   cout<< "popStack over stack size"<<endl;
	   exit(1);
	}
	return e;
}
int main()
{
   sNode ps;
   psNode ptrs = &ps;
   initStack(ptrs);
   for(int i = 0;i<10;i++)
   {
      pushStack(ptrs,i);
   }
   for(int i = 0;i<10;i++)
   {
      cout<<":"<<popStack(ptrs) ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ;
   }
}