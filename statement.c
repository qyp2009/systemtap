#include <stdio.h>

static inline int sub(int b){
	int c=b;
	c--;
	return c;
}

int main(int argc,char *argv[]){
	int a=6;
	printf("a=%d\n",a);
	a++;
	printf("a++=%d\n",a);
	printf("a--=%d\n",sub(a));
	return 0;
}

