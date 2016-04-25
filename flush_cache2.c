#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int size = (long long int)1024 * 1024 * 13;
	char *pointer = (char*)malloc(size);

	while(1)
	{
		for(long long int i = 1; i<size; i += 64)
		{
			pointer[i]=0;
		}
		//printf("iteration %d\n",ii++);
	}
	return 0;
}
