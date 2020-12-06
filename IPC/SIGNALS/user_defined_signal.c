#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<signal.h>

//callback functions
void SignalHandler1(int Number)
{
	printf("Task started : Signal 1 received.\n");
}

void SignalHandler2(int Number)
{
	printf("Task finished : Signal 2 received.\n");
}

int main()
{
	printf("Process is running.");
		
	signal(SIGUSR1,SignalHandler1);
	signal(SIGUSR2,SignalHandler2);
	
	for(;;);
	
	return 0;
}
