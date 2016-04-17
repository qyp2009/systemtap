#include <stdio.h>

int main(int argc,char *argv[]){
	int a=6;
	printf("a=%d\n",a);
	a=add(a);
	printf("a=%d\n",a);
	return 0;
}

int add(int b){
	return b+8;
}
