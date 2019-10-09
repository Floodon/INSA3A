#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char* nom;
    char num[10];
} Personne;

int main(void) {
    int i;
    char nom_tmp[100];
    Personne repertoire[10];
    for(i=0;i<3;i++) {
        scanf("%s",nom_tmp);
        repertoire[i].nom = (char*)malloc((strlen(nom_tmp)+1)*sizeof(char));
        strcpy(repertoire[i].nom,nom_tmp);
        scanf("%s",repertoire[i].num);
    }
    for(i=0;i<3;i++) {
        printf("%s\n%s\n",repertoire[i].nom,repertoire[i].num);
        free(repertoire[i].nom);
    }


	return EXIT_SUCCESS;
}
