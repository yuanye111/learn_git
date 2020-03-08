#include "sys/types.h"
#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "signal.h"

void myfunc(int signalnum)
{
    printf("i receieved a signal :%d\n",signalnum);
    return;
}
void myfunc1(int signalnum)
{
   int waitstatus;
   printf("i know that the child  stopped : %d\n",signalnum);
   wait(&waitstatus);
}
int main()
{
        pid_t pid;
	pid = fork();
	if(pid > 0)
	{
	   int i =0;
	   signal(10,myfunc);
	   signal(17,myfunc1);
	   while(1)
	   {
	      printf("parent process do his own business,i=%d\n",i);
	      sleep(1);
	      i++;
	   }
	}
	if(pid == 0)
	{
	  sleep(10);
	  kill(getppid(),10);
	  sleep(10);
	  exit(0);
	}
        return 0;

}



