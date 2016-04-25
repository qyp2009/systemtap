#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int size = (long long int)1024 * 1024 * 1024 * 6;
	char *pointer = (char*)malloc(size);
	long long int ii = 0;
	while(1)
	{
		for(long long int i = 1 ; ; i = i * 16807 % 2147483647)
		{
			pointer[i]=0;
		}
		//printf("iteration %d\n",ii++);
	}
	return 0;
}
