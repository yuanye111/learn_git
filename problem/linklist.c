#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define false 0
#define true 1
typedef struct LNode
{
   int data;
   struct LNode *next;	
} LNode,*LinkList;

void InsertNode(LinkList head,int prior){
    LinkList ins = (LinkList)malloc(sizeof(LNode));
    ins->data = prior;
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
  int FrontData = -1;
  int JobCounts=5,MyJob;
  int CurJob;
  int MyPos;
  int i;
  LinkList first,cur;
  int mins = 0;
  LinkList head = (LinkList)malloc(sizeof(LNode));
  head->data = -1;
  head->next = head;
  first = head->next;


  scanf("%d",&cases);

  while(cases > 0)
  {
    scanf("%d %d",&JobCounts,&MyPos);
    for(i = 0;i<JobCounts;i++){
      scanf("%d",&CurJob);
      
      if(MyPos = i)
      	MyJob = CurJob;

      InsertNode(head,CurJob);
      i++;
    }
   do{
      if(CheckJob(head) == 1)
      {
        FrontData = head->next->data;
      	DeleNode(head);
        mins++;
      }
      else{
        MoveNode(head);
      }
     }while(FrontData != MyJob);
    
    printf("%d",mins);
    cases--;
  }

}

