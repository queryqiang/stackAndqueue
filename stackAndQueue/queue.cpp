#include<iostream>
using namespace std;
const int queueSize = 20;
typedef struct linearQueue{
   int  queueSize;
   int  front;
   int rear;
   int *pBase;
}linearQueue,*plinearQueue;
int init_queue(plinearQueue ptr)
{
	ptr->pBase = (int*)malloc(sizeof(int)*queueSize);
	if(NULL == ptr->rear)
	{
	   cout<<"init_queue fail malloc queue"<<endl;
	   exit(1);
	}
	ptr->front = 0;
	ptr->rear = 0;
	ptr->queueSize = queueSize;
	return 1;
}
bool is_full_queue(plinearQueue ptr)
{
   if((ptr->rear-ptr->front ) > queueSize )
   {
      return true;
   }
   else
	   return false;
}
bool is_empty_queue(plinearQueue ptr)
{
	if(ptr->front == ptr->rear)
	{
	  return true;
	}
	else
		false;
}
int push_to_queue(plinearQueue ptr,int e)
{
	if(true == is_full_queue(ptr)  )
	{
	   cout << " queue overflow"<<endl;
	   exit(1);
	}
	else
	{
	  ptr->rear = e;
	  (ptr->rear)++;
	}
	return 1;
}
int pop_from_queue(plinearQueue ptr)
{
	int re;
	if(true == is_empty_queue(ptr))
	{
	   cout<<"pop arrived end"<<endl;
	   exit(1);
	}
	else
	{
		re  = ptr->front;
		(ptr->front)++;
		return  re;
	}
	return 1;
}
int main3()
{
    linearQueue lq;
	plinearQueue pl = &lq;

	init_queue(pl);

	for(int i = 0;i<10;i++)
	{
	  push_to_queue(pl,i);
	}

	for(int i = 0;i<10;i++)
	{
	  cout<<":"<< pop_from_queue(pl);
	}
	return 1;
}