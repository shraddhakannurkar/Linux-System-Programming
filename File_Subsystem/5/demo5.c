#include<stdio.h>
#include<fcntl.h>
#include<limits.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX_SIZE 1024

int main(int argc, char *argv[])
{

	int fd = 0, iread = 0;
	char arr[MAX_SIZE + 1];
	
	
	if(argc != 3)
	{
		printf("Error : Insufficient Arguments");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error : Unable to open the file");
		return -1;
	}
	else
	{
		printf("File opened successfully with fd : %d\n",fd);
		
		int bytes = atoi(argv[2]);
		iread = read(fd,arr,bytes);
		arr[iread] = '\0';
		if(iread == -1)
		{
			printf("Error : Unable to read data.\n");
			return -1;
		}
		else
		{
			printf("Data is : %s\n",arr);
			close(fd);
		}
	}

	return 0;
}

