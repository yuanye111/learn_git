#include "semun.h"
#include "svshm_xfr.h"


int main()
{
     stuct shmseg* shmaddr; 
     int xfrs,bytes;
     union semun dummy;

	 semid = semget(SEM_KEY, 2 , IPC_CREAT | OBJ_PERMS);
	 if(semid == -1)
	 	printf("semget\n");
	 if(initSemAvalable(semid,WRITE_SEM) == -1)
	 	printf("initSemAvalable failed one WRITE_SEM\n");
	 if(initSemInUse(semid,READ_SEM) == -1)
	 	printf("initSemAvalable failed one READ_SEM\n");

	 shmid = shmget(SHM_KEY,sizeof(stuct shmseg),IPC_CREAT | OBJ_PERMS);
	 if(shmid == -1)
	 {
	 	printf("shmget failed\n");
	 }
     shmaddr = shmat(shmid,NULL,0);
     if(shmaddr == (void *) -1)
     	printf("shmat\n");

   for(xfrs = 0, bytes = 0; ;xfrs++,bytes += shmp->cnt){
    if(reserveSem(semid,WRITE_SEM) == -1)
    {
        errExit("reserveSem");
    }
    shmp->cnt = read(STDIN_FILENO, shmp->buf, BUF_SIZE);
    if(shmp->cnt == -1)
       printf("read\n");
   
    if(releaseSem(semid,READ_SEM) == -1)
    	printf("releaseSem failed\n");
    
    if(shmp->cnt == 0)
     	break;
    }

    if(reserveSem(semid,WRITE_SEM) == -1)
    	printf("reserveSem\n");

    if(semctl(semid,0,dummy) == -1)
        printf("semctl");
    if(shmdt(shmp) == -1)
        printf("shmdt");
    if(shmctl(shmid,IPC_RMID,0) == -1)
        printf("shmctl");

    fprintf(stderr, "sent %d bytes (%d xfrs)\n", bytes,xfrs);

}


