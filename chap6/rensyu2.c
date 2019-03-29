/**
 * 練習問題2 stdio APIを使って’wc -l’相当のものを作れ
 */

#include<stdio.h>

int main(int argc,char *args[]){
	if (argc <2){
		fprintf(stderr,"need argc > 2\n");
	}
	FILE *file = fopen(args[1],"r");
	
	int line_count = 0;
	char readed;
	for(;;){
		readed = getc(file);
		if(readed == EOF) break;
		if((char )readed =='\n') line_count += 1;
	}
	printf("%d\n",line_count);

	return 0;


}
