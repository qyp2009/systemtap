#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	char s1[100]="{xxxx17834972891478xxxx}";
	char s2[100]="aaaahelloxcooperbbbb";
	char buf[600];
	*(int *)(s1+1) = 0x81828384;
	*(int *)(s1+19) = 0x81828384;
	int len1=strlen(s1);
	int len2=strlen(s2),len,i;
	for(i=0,len=0;i<3;i++){
		s1[5]=i+'0';
		memcpy(buf+(len1+len2)*i,s1,len1);
		memcpy(buf+(len1+len2)*i+len1,s2,len2);
		len+=len1+len2;
	}
	
	printf("%s\n",buf);
	int n = len_with_skb_id(buf,len2*i);
	printf("real size:%d\n",n);
	
	delete_skb_id(buf,34);
	printf("%s\n",buf);

	delete_skb_id(buf+33,n-33);
	printf("%s\n",buf+33);
	return 0;
}

int is_finger_print(char *buf){
	return 0x81828384 == *(int *)buf ? 1 :0;
}

void delete_skb_id(char *buf,int alength){	
	int i,k;
	int skb_begin,data_begin;
	int skb_id_flag=0,skb_begin_valid=0;
	static char s[50];

	i=k=0;
	skb_begin=data_begin=0;

	if(buf[i]!='{'){
		printf("%s\n",s);
	}
	while(i<alength){
		if(!skb_id_flag){ 
			if(buf[i]=='{' && is_finger_print(buf+i+1) ){
				if(skb_begin != data_begin ){
					memcpy(buf+skb_begin, buf+data_begin, i - data_begin);
					skb_begin += i - data_begin;
					data_begin=skb_begin;
				}
				if(!skb_begin_valid){
					skb_begin=i;
					skb_begin_valid=1;
				}
				i+=5;
				k=0;
				skb_id_flag = 1;
			}else{
				i++;
			}
		}else{
			if(buf[i+k]==(char)0x84 &&  is_finger_print(buf+i+k) ) {
				snprintf(s,50,"%*.*s",k,k,buf+i);
				printf("%s\n",s);
				i += k+5;
				k=0;
				data_begin=i;
				skb_id_flag =0;
			}else{
				k++;
			}
		}
	}
	if(skb_begin != data_begin ){
		memcpy(buf+skb_begin, buf+data_begin, i - data_begin);
		skb_begin += i - data_begin;
	}
	buf[skb_begin]='\0';
}

int len_with_skb_id(char *buf,int length){
	int i,len,k;
	int skb_id_flag=0;
	for(i=len=0;len<length;){
		if(!skb_id_flag){ 
			if(buf[i]=='{' && is_finger_print(buf+i+1) ){
				i+=5;
				skb_id_flag = 1;
				k=0;
			}else{
				len++;
				i++;
			}
		}else{
			if(buf[i+k]==(char)0x84 &&  is_finger_print(buf+i+k) ) {
				//printf("%*.*s\n",k,k,buf+i);
				i += k+5;
				skb_id_flag =0;
				k=0;
			}else{
				k++;
			}
		}
	}
	return i;
}

/*

//eg:.....:cooper}databegin.....
//find begin of "databegin"
int begin_copy_pos(char *s,int start,char *match){
	int i,mlen=strlen(match);
	for(i=start;i<start+200;i++){
		if(id_end[0]==s[i] && !strncmp(s+i+1,match+1,mlen-1)){
			return i+mlen;
		}
	}
	return -1;
}

//eg:.....dataend{cooper:.....
//find end of "dataend"
int end_copy_pos(char *s,int start,int pos,int len,char *match){
	int i,mlen=strlen(match);
	for(i=start;i<len-pos;i++){
		if(id_end[0]==s[i] && !strncmp(s+i+1,match+1,mlen-1)){
			return i-1;
		}
	}
	return i;
}

void delete_skb_id(char *s,int len){
	int pos,bpos,epos;

	epos = end_copy_pos(s,0,len);
	pos = epos+1;
	while(pos<len){
		//data need move
		bpos = begin_copy_pos(s,epos+1,len);
		epos = end_copey_pos(s,bpos+n,len);
		strncpy(s+pos, s+bpos, epos-bpos+1);
		pos += epos-bpos+1;
	}
	s[pos]='\0';
}
*/
