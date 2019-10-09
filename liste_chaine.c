#include<stdio.h>
#include<stdlib.h>

typedef struct _elem {
    int value;
    struct _elem* next;
    } elem;

elem* list = NULL;

int ajouter_en_tete() {
    int v;
    printf("Nombre à ajouter en tête: ");
    scanf("%d",&v);
    elem* e = malloc(sizeof(elem));
    e->value = v;
    e->next = list;
    list = e;
    return EXIT_SUCCESS;
}

int ajouter_en_queue() {
    if(list == NULL) {
        ajouter_en_tete();
        return EXIT_SUCCESS;
    }
    int v;
    printf("Nombre à ajouter en queue: ");
    scanf("%d",&v);
    elem* next = list;
    elem* e = malloc(sizeof(elem));
    e->value = v;
    e->next = NULL;
    while(1) {
        if(next->next != NULL) {
            next = next->next;
        } else {
            next->next = e;
            break;
        }
    }
    return EXIT_SUCCESS;
}

void afficher(void) {
    if(list != NULL) {
        printf("-> %d\n",list->value);
        elem* next = list->next;
        while(1) {
            if(next != NULL) {
                printf("-> %d\n",next->value);
                next = next->next;
            } else {
                printf("-> Fin de la liste\n");
                break;
            }
        }
    } else printf("-> liste vide\n");
}

void rechercher(void) {
    if(list != NULL) {
        int n,i=0;
        printf("Nombre à rechercher: ");
        scanf("%d",&n);
        elem* next = list;
        while(1) {
            if(next != NULL) {
                if(next->value == n) printf("Position %d\n",i);
                next = next->next;
                i++;
            } else break;
        }
    } else printf("-> liste vide\n");
}

void supprimer(void) {
    if(list != NULL) {
        int n,i=0;
        printf("Nombre à supprimer: ");
        scanf("%d",&n);
        elem* current = list;
        elem* previous = NULL;
        if(current->value == n) {
            if(current->next == NULL) {
                free(current);
                list = NULL;
                return;
            } else {
                list = current->next;
                free(current);
            }
        }
        while(1) {
            if(current != NULL) {
                if(current->value == n) {
                    if(current->next == NULL) {
                        previous->next = NULL;
                        free(current);
                        break;
                    } else {
                        previous->next = current->next;
                        free(current);
                        current = previous->next;
                        continue;
                    }
                }
                previous = current;
                current = current->next;
            } else break;
        }
    } else printf("-> liste vide\n");
}



int main(int argc, char** argv) {
	if (argc != 1) {
		printf("usage: ./%s <arg1> <arg2>\n",argv[0]);
		return EXIT_FAILURE;
	}
    while(1) {
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t3: rechercher dans la liste\n");
        printf("\t4: ajouter en queue\n");
        printf("\t5: supprimer une valeur de la liste\n");
        printf("\t0: quitter\n");
        int choix;
        scanf("%d", &choix);
        switch(choix) {
            case 0:
                goto fin;
            case 1:
                ajouter_en_tete();
                break;
            case 2:
                afficher();
                break;
            case 3:
                rechercher();
                break;
            case 4:
                ajouter_en_queue();
                break;
            case 5:
                supprimer();
                break;
            default:
                printf("choix incorrect\n");
                continue ;
                // revenir au menu
        }
    }
    fin:
        printf("-> au revoir\n");
	return EXIT_SUCCESS;
}