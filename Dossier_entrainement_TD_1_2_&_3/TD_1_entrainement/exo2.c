#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct chainon{
    int element;
    struct chainon * suivant;
}Chainon;

Chainon * creationChainon(int a){
    Chainon * nouveau = malloc(sizeof(Chainon));
    if(nouveau == NULL){
        exit(1);
    }
    nouveau -> element = a;
    nouveau -> suivant = NULL;
    return nouveau;
}

Chainon * insertDebut(Chainon * pliste, int a){
    Chainon * nouveau = creationChainon(a);
    nouveau -> suivant = pliste;
    pliste = nouveau;
    return pliste;
}

Chainon * insertFin(Chainon * pliste, int a){
    Chainon * nouveau = creationChainon(a);
    Chainon * p1 = pliste;
    if(pliste == NULL){
        return nouveau;
    }

    while(p1->suivant != NULL){
        p1 = p1 -> suivant;
    }
    p1 -> suivant = nouveau;
    return pliste;
}

void afficheListe(Chainon * pliste){
    Chainon * remplacement = malloc(sizeof(Chainon));
    if(pliste == NULL){
		printf("Liste NULL");
	}
    while (pliste -> suivant != NULL){
        if(pliste -> suivant -> element <= pliste -> element){
            remplacement -> element = pliste -> element;
            pliste -> element = pliste -> suivant -> element;
            pliste -> suivant -> element = remplacement -> element;
        }
        printf("%d->", pliste->element);
        pliste = pliste->suivant;
    }
    printf("%d", pliste->element);
    free(remplacement);
}


int main(){
    Chainon * liste = NULL;
    int choix_element;
    int taille;
    printf("Veuillez choisir la taille de la liste\n");
    scanf("%d",&taille);
    printf("\n");
    for(int i = 0; i < taille; i++){
        printf("\nchoisir l'element\n");
        scanf("%d",&choix_element);
        liste = insertFin(liste,choix_element);
    }
    printf("\n");

    afficheListe(liste);

    printf("\n");
    return 0;
}