/**
 * 練習問題3.fread()とrwrite()をつかってcatコマンドを書きなさい
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* args[]){
	if (argc != 2){
		fprintf(stderr,"need 1 arguments\n");
		exit(1);
	}	
	FILE *file = fopen(args[1],"r");
	if(file == NULL) {
		fprintf(stderr,"%s no such file\n",args[1]);
		exit(1);
	}
	int BUFFER_SIZE = 2048;
	char buffer[BUFFER_SIZE];

	fread(buffer,BUFFER_SIZE,1,file);
	fwrite(buffer,strlen(buffer),1,stdout);

}
