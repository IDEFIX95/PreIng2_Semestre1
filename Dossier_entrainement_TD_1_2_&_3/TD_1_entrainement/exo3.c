#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>


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

Chainon * insertFin(Chainon * pliste, int a){
    Chainon * nouveau = creationChainon(a);
    Chainon * p1 = pliste;
    if(pliste == NULL){
        return nouveau;
    }
    while(p1 -> suivant != NULL){
        p1= p1 -> suivant
    }
    p1 -> suivant = nouveau
    return pliste;
}

void afficheListe(Chainon * pliste){

}


int main(){
    srand(time(NULL));
    int taille;
    printf("Veuillez selectionner la taille de la liste\n");
    scanf("%d",taille);

    int valeurs = rand()%5;
    Chainon * liste = creationChainon(valeurs);

    for(int i = 0; i<taille; i++){ 
        valeurs = rand()%5;
        liste = insertFin(liste,valeurs);
    }
    return 0;
}