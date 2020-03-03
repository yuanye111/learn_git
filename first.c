#include "unistd.h"
#include "stdio.h"
#include "sys/types.h"
#include "stdlib.h"
int main()
{
    int i;
	for (i = 0; i < 5; ++i)
	{
		printf("this is first process\n");
		usleep(100);
	}
	while(1);
	return 0;
}