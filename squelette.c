#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("usage: ./%s <arg1> <arg2>\n",argv[0]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
