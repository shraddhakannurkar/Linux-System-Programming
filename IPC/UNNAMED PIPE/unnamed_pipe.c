#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>

int main()
{
	int ret = 0, ret1 = 0;
	char arr[10] = {'\0'};
	
	//Array of file descriptors for pipe
	//fd[1] for writing
	//fd[0] for reading
	int fd[2] = {0,0};
	
	//create unnamed pipe
	pipe(fd);
	
	ret = fork();
	
	//Reader process
	if(ret == 0)
	{
		close(fd[1]);
		read(fd[0],arr,10);
		printf("Child running.\n");
		printf("Child received data 1 : %s\n", arr);
		ret1 = lseek(fd[0],2,SEEK_CUR);
		read(fd[0],arr,10);
		printf("Offset is : %d\n",ret1);
		printf("Child received data 2 : %s\n", arr);
	}
	
	//Writer process
	else
	{
		close(fd[0]);
		write(fd[1],"MarvellousInfosystems",21);
		printf("Parent running.\n");
		printf("Data written by parent in pipe.\n");
	}
	
	return 0;
}
