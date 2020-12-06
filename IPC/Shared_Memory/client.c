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
	shmid = shmget(key,SHMSZ,IPC_CREAT);
	
	//Attach the segment to Data Space
	shm = shmat(shmid,NULL,0);
	
	//Now read what the server has put in memory
	for(s = shm;*s != NULL;s++)
		putchar(*s);
	putchar('\n');
	
	//Finally change the first character of the segment to '*' indicating
	//we have read the data.
	*shm = '*';
	
	exit(0);
}
