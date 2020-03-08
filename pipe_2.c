#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
int main()
{
	int *fd = (int*)malloc(sizeof(int)*2);//[2];
	int ret;
    //int uid = fork();
    char write_buf[] = "hello linux";
    char read_buf[128] = {0};
	ret = pipe(fd);
	if(ret < 0)
	{
		printf("creat pipe failed\n");
		return -1;
	}
	printf("creat pipe success fd[0]=%d,fd[1]=%d\n",fd[0],fd[1]);
	write(fd[1],write_buf,sizeof(write_buf)-1);
	write(fd[1],"kernel pipe",12);
	read(fd[0],read_buf,strlen(write_buf));
	read(fd[0],&read_buf[11],12);
	printf("%s",read_buf);

	close(fd[0]);
	close(fd[1]);
	return 0;

}



