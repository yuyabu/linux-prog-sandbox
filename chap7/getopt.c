#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	
	int opt;

	while((opt = getopt(argc, argv, "af:")) != -1){
		
		switch (opt) {

			case 'a':
				//オプションaを処理するコード
				printf("arg a\n");
				break;
			case 'f':
				//オプション-fを処理するコード
				printf("arg f\n");
				break;
			case '?':
				printf("arg ?\n");
				//不正なオプションを渡された場合のコード
				break;
		}

	}
	printf("program finished\n");
}
