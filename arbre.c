#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* generate_boules(int nb_boules) {
	int i;
	int* tab = malloc(nb_boules*sizeof(int));
	srand(time(NULL));
	for (i=0;i<nb_boules;i++) {
		tab[i]=rand();
	}
	return tab;
}


int main(int argc, char** argv) {
	if (argc != 5) {
		printf("usage: %s <hauteur du cone> <largeur du tronc> <hauteur du tronc> <nb de boules>\n",argv[0]);
		return EXIT_FAILURE;
	}
	int h_cone = (int)strtol(argv[1],NULL,0);
	int l_tronc = (int)strtol(argv[2],NULL,0);
	int h_tronc = (int)strtol(argv[3],NULL,0);
	int l_cone = 1+2*(h_cone-1);
	int i,j,k,nb_star=1,cpt=0;
	int boule = 0;
	int nb_feuille = (l_cone/2)*(h_cone)+h_cone;
	int nb_boules = (int)strtol(argv[4],NULL,0);
	int* tab = generate_boules(nb_boules);
	for(i=h_cone;i>0;i--) {
		for(j=0;j<=l_cone;j++) {
			if(j<i || j>=i+nb_star) printf("_");
			else {
				for(k=0;k<nb_boules;k++) {
					if(tab[k]%nb_feuille==cpt) {
					       	printf("O");
						boule = 1;
					}
				}
				if(boule==0) printf("*");
				boule = 0;
				cpt++;
			}
		}
		nb_star+=2;
		printf("\n");
	}

	for(i=h_tronc;i>0;i--) {
		for(j=0;j<=l_cone;j++) {
			if(j<h_cone-l_tronc/2 || j>h_cone+l_tronc/2) printf(" ");
			else printf("|");
		}
		printf("\n");
	}


		
	return EXIT_SUCCESS;
}
