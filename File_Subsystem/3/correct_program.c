#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char* argv[])
{
        int ret = 0;

        if(argc < 3)
        {
                printf("Insufficient argument specified\n");
                printf("Help : file_access <file_path> < [F_OK] | [R_OK] | [W_ OK] | [X_ OK]>\n");
                return(0);
        }

        if(!(strcmp(argv[2],"F_OK")))
        {
                ret = access(argv[1],F_OK);
                if(ret == -1)
                {
                        printf("File does not exist!\n");
                        return(0);
                }
                else
                        printf("%s exists\n",argv[1]);
        }



        if(!(strcmp(argv[2],"R_OK")))
        {
                ret = access(argv[1],R_OK);
                if(ret == -1)
                {
                        printf("\nYou do not have read permissions on %s file\n", argv[1]);
                        return(0);
                }
                else
                        printf("%s can be read\n",argv[1]);
        }



        if(!(strcmp(argv[2],"W_OK")))
        {
                ret = access(argv[1],W_OK);
                if(ret == -1)
                {
                        printf("You do not have write permissions on %s.\n", argv[1]);
                        return(0);
                }
                else
                        printf("%s can be written\n",argv[1]);
        }



        if(!(strcmp(argv[2],"X_OK")))
        {
                ret = access(argv[1],X_OK);
                if(ret == -1)
                {
                        printf("You do not have execute  permission on file %s.\n", argv[1]);
                        return(0);
                }
                else
                        printf("%s can be executed\n",argv[1]);
        }




        return(0);
}
