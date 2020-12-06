#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"Library.h"

int main()
{
	
	int value1 = 10, value2 = 11, ret;
	
	ret = add(value1, value2);
	printf("Addition is : %d\n", ret);
	
	ret = mult(value1, value2);
	printf("Multiplication is : %d\n", ret);
	
	return 0;
}
