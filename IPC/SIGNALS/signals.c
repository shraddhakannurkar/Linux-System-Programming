#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<signal.h>


void SignalHandler(int Number)
{
	printf("Signal received with number : %d",Number);
}

int main()
{
	printf("Process is running with PID : %d\n",getpid());
		
	signal(SIGKILL,SignalHandler);
	
	for(;;);
		
	return 0;
}
