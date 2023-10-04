#include <stdio.h>
#include <stdlib.h>

typedef struct piledyn{
    int element;
    struct piledyn * suivant;
}Piledyn;


Piledyn * empiler(Piledyn * pile,int valeur){
    Piledyn * nouveau = malloc(sizeof(Piledyn));
    if(nouveau == NULL){
        printf("erreur");
        exit(1);
    }
    nouveau -> element = valeur;
    nouveau -> suivant = pile;
    pile = nouveau;
    return pile;
}

void affichePile(Piledyn * pile){
    Piledyn * p = pile;
    while(pile != NULL){
        printf("%d", p ->suivant);
        p -> suivant;
    }
}

void affichePileRecursif(Piledyn * pile){
    if(pile != NULL){
        printf("%d", pile -> element);
        affichePileRecursif(pile -> suivant);
    }
}



Piledyn * depile(Piledyn * pile, int * pnmb){
    Piledyn * p = pile;
    if(p == NULL){
        printf("impossible de depiler");
        exit(1);
    }
    *pnmb = p -> element;
    pile = p -> suivant;
    free(p);
    return pile;
}
