#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	if(argc != 3){
		fprintf(stderr,"need 2 args\n");
	}
	int dividend = atoi(argv[1]);
	int divisor = atoi(argv[2]);
	
	float result = dividend / divisor;
	printf("%d / % d is %f\n", dividend,divisor,result);
		
}
