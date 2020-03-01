#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int fd[2];
	int ret;
    //int uid = fork();
    char write_buf[] = "hello linux kernel pipe";
    char read_buf[128] = {0};
	ret = pipe(fd);
	if(ret < 0)
	{
		printf("creat pipe failed\n");
		return -1;
	}
	printf("creat pipe success fd[0]=%d,fd[1]=%d\n",fd[0],fd[1]);
	write(fd[1],write_buf,sizeof(write_buf));
	read(fd[0],read_buf,128);
	printf("%s",read_buf);
	return 0;

}



