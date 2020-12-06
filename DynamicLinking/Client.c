#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
	void *lib = NULL;
	
	//int add(int no1, int no2);
	int (*fptr1)(int, int); //creating the function pointer
	int (*fptr2)(int, int);
	
	int value1 = 10, value2 = 11, ret;
	
	printf("Loading the library dynamically\n");
	
	lib = dlopen("./Library.so", RTLD_LAZY);
	if(lib == NULL)
	{
		printf("Unable to link the Library\n");
		return -1;
	}		
	
	printf("Library loaded successfully\n");
	printf("Fetching the address of add function\n");
	
	fptr1 = dlsym(lib, "add"); //dynamic linking madhla symbol pahije ani ata add cha address kadhun anycha ahe fptr madhe
	if(fptr1 == NULL)
	{
		printf("Unable to get address of add function\n");
		return -1;
	}
	
	printf("Address of add function fetched successfully\n");
	
	ret = fptr1(value1, value2);
	printf("Addition is : %d\n", ret);
	
	fptr2 = dlsym(lib, "mult");
	if(fptr2 == NULL)
	{
		printf("Unable to get address address of mult function\n");
		return -1;
	}
	
	printf("Address of mult function fetched successfully\n");
	
	ret = fptr2(value1, value2);
	printf("Multiplication is : %d\n", ret);
	
	dlclose(lib);
	printf("Dynamic Library unlinked successfully\n");
	
	for(;;);
	
	return 0;
}
