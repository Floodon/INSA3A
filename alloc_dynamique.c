#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
    int* tab = malloc(argc-1*sizeof(int));
    int i;
    for(i=0;i<argc-1;i++) {
        tab[i]=(int)strtol(argv[i+1],NULL,0);
    }
    return EXIT_SUCCESS;
}
