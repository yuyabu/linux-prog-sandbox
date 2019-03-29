/**
 * p132 練習問題1.タブ文字(\t)をi「\t」という2文字、改行を「$ + 改行」の2文字として置き換えながら出力するcatコマンドを書きなさい
 * 
 */
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
