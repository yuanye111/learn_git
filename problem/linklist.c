#include<stdio.h>
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

bool CheckJob(LinkList head){
     first = head->next;
     if(first->next==head)
     	return true;

      cur = first ->next;
      while(cur->next != head)
      {
         if(cur->data > first->data){
	  return false;
	 }
	 else
	 {
	   cur = cur->next;
	 }
      }
      return ture;
}

int main()
{
  int cases;
  int JobCounts,MyJob;
  int CurJob;
  LinsList first,cur;
  int mins = 0;
  LinkList head = (LinkList)malloc(sizeof(LNode));
  head->data = -1;
  head->next = head;
  first = head->next;

  scanf("%d",&cases);

  while(cases > 0)
  {
    scanf("%d,%d",&JobCounts,&MyJob);
    while(JobCounts>0){
      scanf("%d",&CurJob);
      InsertNode(head,CurJob);
      JobCounts--;
    }
   do{
      first = head->next;
      if(CheckJob(head) == 1)
      {
      	DeleNode(head);
      }
      else{
        InsertNode(head,first->data);
      	DeleNode(head);
      }
     minus++;
     }while(first->data != MyJob)
    
    printf("%d",minus);
  }

}

