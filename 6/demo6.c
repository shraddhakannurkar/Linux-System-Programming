#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
        int fd = 0, iread = 0;
        char buffer[MAX_SIZE];

        if(argc != 2)
        {
                printf("Error : Insufficient arguments.\n");
                return -1;
        }

        fd = open(argv[1],O_RDONLY);
        if(fd == -1)
        {
                printf("Error : Unable to open the file\n");
                return -1;
        }

	printf("File %s opened successfully with fd %d.\n",argv[1],fd);
        
 	while( (iread = read(fd,buffer,MAX_SIZE))  > 0)
 	{
		printf("Total bytes read = %d\n", iread);
		write(1,buffer,iread);	
	}
         
	if(iread == -1)
	{
		printf("Error : Unable to read data.\n");
		return -1;
	} 
         
	close(fd);	
        return 0;
}

