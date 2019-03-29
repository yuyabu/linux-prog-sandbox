#include<stdio.h>

int main(/*int args, char *argc[]*/){
	FILE *file = fopen("rensyu1_data","r");	
	int readed=0;
	for(;;){
		readed = fgetc(file);
		if (readed ==EOF) break;
		char ch = (char) readed;
		if(ch == '\t'){
			printf("\\t");
		}else if(ch == '\n'){
			printf("$\n");
		}else{
			printf("%c",(char) readed);
		}
	}	
	

	return 0;
}
