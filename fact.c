#include<stdio.h>
#include<stdlib.h>

int fact(long n) {
	if(n <=1) return 1;
	else return (n*fact(n-1));
	}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("usage: %s <nb>\n",argv[0]);
		return EXIT_FAILURE;
	}
	long n = strtol(argv[1],NULL,0);
	printf("%d\n",fact(n));
	return EXIT_SUCCESS;
}
