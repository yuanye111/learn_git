#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define false 0
#define true 1
typedef struct LNode
{
   int data;
   int pos;
   struct LNode *next;	
} LNode,*LinkList;

void InsertNode(LinkList head,int prior,int pos){
    LinkList ins = (LinkList)malloc(sizeof(LNode));
    ins->data = prior;
    ins->pos = pos;
    LinkList first = head;
    
    while(first->next != head)
	first = first->next;
    
    first->next = ins;
    ins->next = head;
}

void DeleNode(LinkList head){
   LinkList first = head->next;
   head->next = first->next;
   free(first);
}

void MoveNode(LinkList head){
	LinkList node = head->next;
	LinkList first = head->next;
	while(node->next != head){
		node = node->next;
	}
	node->next = first;
	head->next = first->next;
	first->next = head;

}

bool CheckJob(LinkList head){
     LinkList first = head->next;
     LinkList cur;
     
     if(first->next == head)
     	return true;

      cur = first->next;
      while(cur != head)
      {
         if(cur->data > first->data){
	  return false;
	 }
	 else
	 {
	   cur = cur->next;
	 }
      }
      return true;
}

void TransList(LinkList head)
{
  LinkList node = head->next;
  while(node != head)
  {
    printf("%d ",node->data);
    node = node->next;
  }
  printf("\n");
}

int main()
{
  int cases;
  int FrontData;
  int JobCounts;
  int CurJob;
  int MyPos;
  int i;
  int mins = 0;
  LinkList head = (LinkList)malloc(sizeof(LNode));
  head->next = head;
  head->data = head->pos = -1;
  scanf("%d",&cases);
  
  while(cases > 0)
  {
    mins = 0;
    FrontData = -1;
    scanf("%d %d",&JobCounts,&MyPos);
    for(i = 0;i<JobCounts;i++){
      scanf("%d",&CurJob);
      InsertNode(head,CurJob,i);
    }
   do{
      if(CheckJob(head) == true)
      {
        FrontData = head->next->pos;
      	DeleNode(head);
        mins++;
      }
      else{
        MoveNode(head);
      }
     }while(FrontData != MyPos);
   
    while(head->next != head)
    	DeleNode(head);

    printf("%d",mins);
    cases--;
  }

}

