#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	char *buff;
	int size;
	if(argc<2){
		printf("eg:%s <buffer size>\n",argv[0]);
		exit(0);
	}

	size=atoi(argv[1]);
	buff = (char *)malloc(size);
	
	printf("malloc size:%d,%s\n",size,buff<=0?"fail":"success");
	if(buff<=0)
		free(buff);
	return 0;
}
