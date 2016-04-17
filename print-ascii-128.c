#include <stdio.h>

int main(int argc,char *argv[]){
	 char s[50]="{cooper:hello:cooper}";
	 s[1]=0x80;
	 int *s2 = (int *)(s+2);
	 *s2 = 0x81828384;
	 printf("char 0x80:%d,len:%d,str:%s,sizeof(int)=%d\n",
	 	s[1],strlen(s),s,sizeof(int));
	return 0;
}
