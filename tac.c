#include <stdio.h>
#include <stddef.h>
#include <string.h>
char* haha = "cooper\n";
char* read_line(FILE* fp, char* buf, size_t len){ 
  return fgets(buf, len, fp);
}
char* reverse_line(char* line, size_t l){
  char *s = line, *e = s + l - sizeof("\n"), t;
  while(s < e) {  t =*s, *s = *e, *e = t; s++, e--; }
  return line;
}
void write_line(char* line){
  fputs(line, stdout);
}

int main(int argc, char * argv[]){
  char buf[4096], *line;
  FILE* fp = stdin;
  if(argc != 1 ) {fp = fopen(argv[1], "r");}
  if(fp == NULL){fprintf(stdout, "usage: %s filename\n", argv[0]);return -1;}
 
  while((line = read_line(fp, buf, sizeof(buf)))){
    line = reverse_line(line, strlen(line));
    write_line(line);
  }
 
  if(argc != 1) fclose(fp);
  return 0;
}
