#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fd = 0, iwrite = 0;
	char str[] = "Shraddha";
	if(argc != 2)
	{
		printf("Error : Insufficient Arguments.\n");
		return -1;
	}
	
	
	fd = open(argv[1],O_RDWR);
	
	if(fd == -1)
	{
		printf("Error : Unable to open the file.\n");
		return -1;
	}
	
	else
	{
		iwrite = write(fd,str,strlen(str));
		if(iwrite == -1)
		{
			printf("Error : Unable to write the data in file.\n");
			close(fd);
			return -1;
		}
		else
		{
			printf("Data gets written in %s file successfully.\n",argv[1]);
		}
		
	}
	
	return 0;
}
