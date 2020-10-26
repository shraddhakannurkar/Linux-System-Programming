#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Error : Insufficient Arguments\n");
		return -1;
	}
	
	
	int fd = 0;
	
	fd = open(argv[1],0,argv[2]);
	
	if(fd == -1)
	{
		printf("Error : Unable to open the file\n");
		return -1;
	}
	else
	{
		printf("File %s opened successfully with fd %d and mode %s\n",argv[1],fd,argv[2]);
		close(fd);
	} 
		
	return 0;
}

