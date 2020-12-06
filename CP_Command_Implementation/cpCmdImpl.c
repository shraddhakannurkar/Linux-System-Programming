/*
 *  * Implement custom cp command which is used to copy the contents from one file into another file.
 *   *
 *    *
 *     * Usage :
 *      * cp File1.txt File2.txt
 *       * File1.txt contains the data
 *        * We have to create File2.txt and write all the data from File1.txt into it.
 *         *
 *          */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

//cp Demo.txt Hello.txt
////cp argv[1] argv[2]
////Argv[1] Open the file in read mode
////Argv[2] Create new file
//

void CP_Command(char *src, char *dest)
{
	int fdsrc = 0, fddest  = 0, ret = 0;
        char buffer[1024] = {'\0'};

	fdsrc = open(src,O_RDONLY);
        if(fdsrc == -1)
        {
                printf("Unale to open the source file ie : %s\n",src);
                return;
        }

        fddest = creat(dest,0777);
        if(fddest == -1)
        {
                printf("Unable to create the destination file ie : %s\n",dest);
                return;
        }

        while((ret = read(fdsrc,buffer,sizeof(buffer))) != 0)
        {
                write(fddest, buffer, ret);
        }

        close(fdsrc);
        close(fddest);

        printf("Copy Successful..\n");

}

int main(int argc, char *argv[])
{
        if(argc !=  3)
        {
                printf("Error : Invalid Arguments.\n");
                printf("Usage : CP Source.txt Destination.txt\n");
                return -1;
        }

	CP_Command(argv[1],argv[2]);

	return 0;
}

