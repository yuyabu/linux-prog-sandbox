/**
 * chapter 5の練習問題1.catコマンドでファイル名がわたされなかったら標準入力を読むようにする
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

static void do_stdio_echo();
static void do_cat(const char *path);
static void die(const char *s);

int main(int argc, char *argv[]){

	if (argc < 2){
		do_stdio_echo();
	}else{

		for (int i = 1; i< argc;i++){
			do_cat(argv[i]);
		}
	}
	exit(0);
}

#define BUFFER_SIZE 2048
static void do_stdio_echo(){
	//stdioを1回読んで出力して終わり。
	
	int fd = STDIN_FILENO;
	
	unsigned char buf[BUFFER_SIZE];
	int readed_bytes;
	
	for(;;){
		readed_bytes = read(fd, buf,sizeof buf);
		if (readed_bytes ==0) break;
		if(write(STDOUT_FILENO, buf, readed_bytes) < 0) die("stdin");
	}
	
}
static void do_cat(const char *path){

	int fd = open(path, O_RDONLY);

	if(fd < 0) die(path);
	
	unsigned char buf[BUFFER_SIZE];
	int readed_bytes;
	
	for(;;){
		readed_bytes = read(fd, buf,sizeof buf);
		if ( readed_bytes< 0) die(path);
		if (readed_bytes ==0) break;
		if(write(STDOUT_FILENO, buf, readed_bytes) < 0) die(path);
	}
	if(close(fd) <0) die(path);
}


static void die(const char *s){
	perror(s);
	exit(1);
}
