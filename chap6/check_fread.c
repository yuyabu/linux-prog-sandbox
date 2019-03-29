#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
	FILE *stdout_file = fdopen(STDOUT_FILENO,"r+");
	char *hello = "hello world\n";
	fwrite(hello,strlen(hello),1,stdout_file );
}
