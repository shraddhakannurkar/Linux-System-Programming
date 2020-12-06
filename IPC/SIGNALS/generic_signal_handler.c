#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<signal.h>

//callback functions
void SignalHandler(int Number)
{
	switch(Number)
	{
		case SIGHUP:
			printf("Hangup signal.\n");
			break;
		
		case SIGINT:
			printf("Hangup signal.\n");
			break;
		
		case SIGUSR1:
			printf("User defined signal 1.\n");
			break;
			
		case SIGUSR2:
			printf("User defined signal 2.\n");
			break;
	}
}

int main()
{
	int i = 0;
	
	printf("Process is running.\n");
	
	for(i = 1;i < 64;i++)
	{
		signal(i,SignalHandler);
	}
	
	for(;;);
	//sleep(1); //sleep till the time interval
	//wait(); //wait till the death of child process
	//pause(); //waits till any signal arrives
	
	return 0;
}

