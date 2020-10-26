#include<stdio.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{

	int fd = 0;
	
	if(argc != 2)
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
	}

	return 0;
}

