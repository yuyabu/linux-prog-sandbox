//function pointer sample code
#include<stdio.h>

int plus1(int n);

int main(int argc, char *argv[]){

	int (*f)(int); /*pointer variable f is function pointer*/
	int result;

	f = plus1;
	result = f(5);
	printf("%d\n", result);
	exit(0);
}

int plus1(int n){
	return n+1;
}
