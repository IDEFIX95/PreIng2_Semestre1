#include <stdio.h>
#include <stdlib.h>

typedef struct piledyn{
    int element;
    struct piledyn * suivant;
}PileDyn;


PileDyn * creationPile(int valeur){
    PileDyn * nouveau = malloc(sizeof(PileDyn));
    if(nouveau == NULL){
        exit(1);
    }
    nouveau -> element = valeur;
}

PileDyn * empiler(PileDyn * ppile, int valeur){
    PileDyn *nouveau = 
    
}