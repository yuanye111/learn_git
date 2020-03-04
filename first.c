#include<fcntl.h>
#include "unistd.h"
#include "stdio.h"
#include "sys/types.h"
#include "stdlib.h"
#include <sys/stat.h>
int main()
{
    int i;
    int fd;
    char process_inter = 0;
   fd =open("./myfifo",O_WRONLY);
   if(fd<0)
   {
     printf("open myfifo failed\n");
     return -1;
   }
   else
    printf("openmyfifo succesed\n");
  for (i = 0; i < 5; ++i)
  {
    printf("this is first process\n");
    usleep(100);
  } 
    process_inter = 1;
    sleep(5);
    write(fd,&process_inter,1);
	while(1);
	return 0;
}
