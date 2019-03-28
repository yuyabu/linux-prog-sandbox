/**
 * 連取問題2.バッファ中の\nをかぞえることで、ファイルの行数を出力するコマンドをかきなさい(wc -lと同じ機能)
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

static void do_cat(const char *path);
static void die(const char *s);

int main(int argc, char *argv[]){
	if (argc < 2){
		fprintf(stderr, "%s:file name not given\n", argv[0]);
		exit(1);
	}
	for (int i = 1; i< argc;i++){
		do_cat(argv[i]);
	}
	exit(0);
}

#define BUFFER_SIZE 2048

static void do_cat(const char *path){

	int fd = open(path, O_RDONLY);

	if(fd < 0) die(path);
	
	unsigned char buf[BUFFER_SIZE];
	int readed_bytes;
	int line_count=0;

	for(;;){
		readed_bytes = read(fd, buf,sizeof buf);
		for(int  i=0;i<readed_bytes;i++){
			if(buf[i] == '\n') line_count+=1;
		}
		if ( readed_bytes< 0) die(path);
		if (readed_bytes ==0) break;
		//if(write(STDOUT_FILENO, buf, readed_bytes) < 0) die(path);
	}
	printf("%d\n",line_count);
	if(close(fd) <0) die(path);
}

static void die(const char *s){
	perror(s);
	exit(1);
}
