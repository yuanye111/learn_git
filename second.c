#include<fcntl.h>
#include "unistd.h"
#include "stdio.h"
#include "sys/types.h"
#include <sys/stat.h>
#include "stdlib.h"
int main()
{
    int i;
    int fd;
     char process_inter = 0;
    fd = open("./myfifo",O_RDONLY);
    if(fd < 0)
    {
     printf("open myfifo failed");
     return -1;
    }
    else
      printf("open myfifo success");
     read(fd,&process_inter,1);
	while(process_inter == 0);
	for (i = 0; i < 5; ++i)
	{
		printf("this is second process\n");
		usleep(100);
	}
    while(1); 
	return 0;
}
