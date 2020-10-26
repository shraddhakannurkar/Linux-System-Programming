#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{

        int fd = 0;
        struct stat fileInfo;

        if(argc != 2)
        {
                printf("Error : Insufficient Arguments");
                return -1;
        }

        
        fd = stat(argv[1],&fileInfo);

        if(fd == -1)
        {
                printf("Error : Unable to open the file");
                return -1;
        }
        else
        {
                printf("File opened successfully.");
                printf("Information of file is as follows:-\n");
                printf("Name : %s\n", argv[1]);
                printf("Mode : %d\n", (int)fileInfo.st_mode);
                printf("Inode number : %d\n", (int)fileInfo.st_ino);
                printf("Size : %d\n", (int)fileInfo.st_size);
                printf("Link counts : %d\n", (int)fileInfo.st_nlink);
                printf("User ID : %d\n", (int)fileInfo.st_uid);
                printf("Block size : %d\n", (int)fileInfo.st_blksize);
                printf("File permissions : ");
        	if(fileInfo.st_mode & R_OK)
        		printf("read ");
    		if(fileInfo.st_mode & W_OK)
        		printf("write ");
    		if(fileInfo.st_mode & X_OK)
        		printf("execute");
        }

	

        return 0;
}

