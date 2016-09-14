#include<iostream>
using namespace std;

typedef struct queueNode{
     int data;
	 struct queueNode *next; 
}listQueueNode,*plistQueueNode;
typedef struct queue{
   
   plistQueueNode front;
   plistQueueNode rear;
}queue,*pqueue;
plistQueueNode init_queue_node()
{
   plistQueueNode pHead = (plistQueueNode)malloc(sizeof(listQueueNode));
   if(NULL == pHead)
   {
     cout<<"failed pHead memory"<<endl;
   }
   pHead->next = NULL;
   pHead->data = 0;
   return pHead;
}
void init_queue(plistQueueNode pHead,pqueue pq)
{
   
   pq->front = pHead;
   pq->rear = pq->front;
   
}
void push_to_list_queue(plistQueueNode pHead,pqueue pq,int e)
{
   plistQueueNode pqn = pHead;
   while(NULL != pqn->next)
   {
	   pqn = pqn->next;
   }
   plistQueueNode pTemp ;
   pTemp= (plistQueueNode)malloc(sizeof(listQueueNode));
   pqn->next = pTemp;
   if(NULL == pqn->next)
   {
     cout<<"failed malloc push_to_list_queue"<<endl;
	 exit(1);
   }
   pTemp->data = e;
   pTemp->next = NULL;
   
   pq->rear = pTemp;
}
bool is_empty_list_queue(pqueue pq)
{
	if(pq->front == pq->rear)
	{
	   cout<<"list queue is empty"<<endl;
	   return true;
	}
	else
		return false;
}
int pop_from_list_queue(plistQueueNode pHead,pqueue pq)
{
  static plistQueueNode pqn = pHead->next;
  int e;
  if(true == is_empty_list_queue(pq))
  {
     exit(1);
  }
  else
  {
	  pq->front = pqn;
	  e = pqn->data ;
	  pqn = pqn->next;
	  return e;
  }
}
int main()
{
   plistQueueNode pHead = init_queue_node();
   pqueue pq = (pqueue)malloc(sizeof(queue));
   init_queue(pHead,pq);
   for(int i= 1;i<10;i++)
   {
     push_to_list_queue(pHead,pq,i);
   }
   for(int i = 1;i<10;i++)
   {
     cout<<":"<<pop_from_list_queue(pHead,pq);
   }
   return 1;
}