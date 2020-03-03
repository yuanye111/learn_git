#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
 #include <sys/types.h>
    #include <sys/stat.h>
int int main(int argc, char const *argv[])
{
	int ret;
	ret = mkfifo("./myfifo",0777);
	if(ret < 0)
	{
		printf("create fifo failed\n");
	    return -1;
	}
    printf("create myfifo sucess \n");

	return 0; 
}
