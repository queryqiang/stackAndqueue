/*
  ��⣺1.front rearû����ָ�� ����������pBaseָ��ָ�����
        2.�ص�����ж϶��е��п� ����
		3.ѭ�����������Զ���һ�� �����Ƚ��ȳ�
		4.ѭ�����н�������Զ����˷��ڴ�ռ������
*/
#include<iostream>
using namespace std;
const int queueSize = 20;
typedef struct linearQueue{
   int  queueSize;
   int  front; //ָ����еĵ�һ��Ԫ��
   int rear;//ָ����е����һ��Ԫ�ص���һ��Ԫ��
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
	if(pc->front == ((pc->rear + 1) %pc->queueSize)) //Ԥ��һ���ڴ�ռ����ж϶�����
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