#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	key_t no;
	
	no = ftok("/home/shraddha/Desktop/LSP/IPC/FTOK",11);
	
	printf("Key is : %d",no);
	
	return 0;
}
