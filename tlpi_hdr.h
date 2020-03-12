#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "get_num.h"

typedef enum {FALSE,TRUE} Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))

#define SHM_KEY 0x1234
#define SEM_KEY 0x5678
#define OBJ_PERMS (S_IRUSR | S_WUSR | S_IRGRP | S_IWGPR)

#define WRITE_SEM 0
#define READ_SEM 1

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

struct shmseg
{
	int cnt;
	char buf[BUF_SIZE];
};
#endif


