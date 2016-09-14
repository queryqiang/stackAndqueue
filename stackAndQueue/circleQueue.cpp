/*
  理解：1.front rear没有用指针 而是在用了pBase指针指向队列
        2.重点理解判断队列的判空 判满
		3.循环队列与线性队列一样 都是先进先出
		4.循环队列解决了线性队列浪费内存空间的问题
*/
#include<iostream>
using namespace std;
const int queueSize = 20;
typedef struct linearQueue{
   int  queueSize;
   int  front; //指向队列的第一个元素
   int rear;//指向队列的最后一个元素的下一个元素
   int *pBase;
}circleQueue,*pcircleQueue;
int init_circle_queue(pcircleQueue pc )
{
	pc->pBase = (int*)malloc(sizeof(int)*queueSize);
	if(NULL == pc->pBase)
	{
	   cout<<"init failed mallloc memory"<<endl;
	   exit(1);
	}
	pc->front = 0;
	pc->rear = 0;
	pc->queueSize = queueSize;
	return 1;
}
bool is_full_circlequeue(pcircleQueue pc)
{
	if(pc->front == ((pc->rear + 1) %pc->queueSize)) //预留一个内存空间来判断队列满
	{
	  return true;
	}
	else

		false;
}
bool is_empty_circlequeue(pcircleQueue pc)
{
	if(pc->front == pc->rear )
	{
	   return true;
	}
	else
		false;
}
int push_to_circlequeue(pcircleQueue pc,int e)
{
   if(true == is_full_circlequeue(pc))
   {
      cout<<"circle is full"<<endl;
	  exit(1);
   }
   else
   {
	   pc->pBase[pc->rear] = e;
	   pc->rear = (pc->rear + 1)%pc->queueSize;
   }
   return 1;
}
int pop_from_circlequeue(pcircleQueue pc)
{
   int e = 0;
    if(true == is_empty_circlequeue(pc))
	{
	   cout<<"circle is empty"<<endl;
	   exit(1);
	}
	else
	{
	   e = pc->pBase[pc->front];
	   pc->front = (pc->front + 1)%(pc->queueSize);
	}
	return e;
}
int main2()
{
	circleQueue cq;
	pcircleQueue pc = &cq;
   init_circle_queue(pc);
   for(int i = 0;i <10;i++)
   {
     push_to_circlequeue(pc,i);
	 
   }
   for(int i = 0;i<10;i++)
   {
     cout<<":"<<pop_from_circlequeue(pc);
   }
   return 1;
}