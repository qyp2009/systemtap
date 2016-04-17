#include <stdio.h>

int main(int argc,char *argv[]){
	
}

const char id_begin[]="{cooper:";
const char id_end[]=":cooper}";


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
