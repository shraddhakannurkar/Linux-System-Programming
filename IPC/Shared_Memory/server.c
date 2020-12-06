#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

#define SHMSZ 1024

int main()
{
	char c;
	int shmid;
	key_t key;
	char *shm, *s;
	
	//Naming shared memory segment as 5678
	key = 5678;
	
	//create the segment
	shmid = shmget(key,SHMSZ,IPC_CREAT | 0666);
	
	//Attach the segment to Data Space
	shm = shmat(shmid,NULL,0);
	
	//Add something to memory for other processes to read
	s = shm; //base address of shared memory
	
	for(c = 'a';c <= 'z';c++)
	{
		*s = c;
		s++;
	}
	*s = NULL;
	
	//Wait till other process changes the first character of our process as *
	while(*shm != '*')
		sleep(1);
		
	exit(0);
}
		
	
	
