#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

//myexe FileName
//myexe Argv[1]
//Argv[1] : Name of the file that we want to create

struct FileInfo
{
        char Fname[256]; //File name
        int Fsize;      //File size
};

int main(int argc, char *argv[])
{
	DIR *dp = NULL;
        struct dirent *dip = NULL;
        struct stat sobj;
        int ret = 0;
        int fddest = 0;
        int fdsrc = 0;
        char name[256] = {'\0'};
        struct FileInfo fobj;
        char *Buffer;

	
	if(argc != 2)
	{
		printf("Error : Inavalid Arguments.\n");
		return -1;
	}

	fdsrc = open(argv[1],O_RDONLY);
	if(fdsrc == -1)
	{
		printf("Unable to open the file.\n");
		return -1;
	}

	while((ret = read(fdsrc,&fobj,sizeof(fobj))) != 0)
	{
		printf("File Name : %s Size : %d\n",fobj.Fname,fobj.Fsize);
		fddest = creat(fobj.Fname,0777);
		if(fddest == -1)
		{
			printf("Unable to create the file.\n");
			return -1;
		}

		//Dynamic memory allocation for data to read
		Buffer = (char*)malloc(fobj.Fsize);
	
		//Read the data from merged file
		read(fdsrc,Buffer,fobj.Fsize);
			
		//Write the data into newly created file
		write(fddest,Buffer,fobj.Fsize);
		
		//Free the allocated memory
		free(Buffer);	
	
		close(fddest);	
//		lseek(fdsrc,fobj.Fsize,SEEK_CUR);
		
	}

	close(fdsrc);

	return 0;	
}

