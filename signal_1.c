#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include <sys/stat.h>
#include "signal.h"
typedef void (*singal_handler)(int);
void myfun(int signum)
{
   int i=0;
   printf("this is myfun0:%d",signum);
   return;

}
void myfun1(int signum)
{
   
   int i=0;
   printf("this is myfun1:%d",signum);
   return;

}
int main(int argc, char const *argv[])
{
	int ret;
        int i=0;
	singal_handler func;
        signal(14,myfun);
	printf("alarm before\n");
	alarm(4);
	printf("alarm after\n");
	while(i<5)
	 {
	  i++;
	  printf("wait before the signal\n");
	  sleep(1);
	 }
       func = signal(14,SIG_DFL);
	func(222);
	printf("alarm before \n");
        alarm(5);
	printf("alarm after\n");
	i = 0;
	while(i<8)
	{
	  i++;
	  sleep(1);
	  printf("process things,i=%d\n",i);
	}
	return 0; 
}
