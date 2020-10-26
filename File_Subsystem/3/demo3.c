#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	if(argc != 3)
	{
		printf("Error : Insufficient Arguments\n");
		return -1;
	}
	
	if((strcmp(argv[2],"O_RDONLY") != 0) && (strcmp(argv[2],"O_WRONLY") != 0) && (strcmp(argv[2],"O_RDWR") != 0))
	{
		printf("Error : Invalid mode.\n");
		printf("Please enter the mode as O_RDONLY or O_RDWR or O_WRONLY.\n");
		return -1;
	}
	
	
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

