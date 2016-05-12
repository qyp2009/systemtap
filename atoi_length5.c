#include <stdio.h>
#include <string.h>

int atoi_length5(char *str_len){
	char slen[6];
	strncpy(slen, str_len, 5);
	slen[5]='\0';
	return atoi(slen);
}

int main(char *argv[], int argc){
	char s[6]="00045";	
	printf("%d\n",atoi_length5(s));
	return 0;
}
