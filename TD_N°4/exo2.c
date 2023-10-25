#include <stdio.h>
#include <stdlib.h>


typedef struct arbre{           // Question 1
    int element;
    struct arbre * fils_gauche;
    struct arbre * fils_droit
}Arbre;


typedef Arbre * parbre;         // Question 2

parbre creerArbre(int a){                   // Question 3
    parbre nouveau = malloc(sizeof(parbre));
    if(nouveau == NULL){
        return NULL;
    }

    nouveau -> element = a;
    nouveau -> fils_droit = NULL;
    nouveau -> fils_gauche = NULL;

    return nouveau;
}

int estVide(parbre a){              // Question 4
    if(a == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int estFeuille(parbre a){           // Question 5
    if( (a->fils_droit == NULL) && (a->fils_gauche == NULL) ){
        return 1
    }
    else{
        return 0;
    }
}

int element(parbre a){      // Question 6
    if (a != NULL ){
        return a->element;
    }              
}


pArbre existeFilsGauche(pArbre a){    // Question 7
    if(estVide(a)){
        printf("l'arbre est vide");
        return NULL;
    }
    if( a->fils_gauche == NULL ){
        return 1;
    }
    else{
        return 0;
    }
}

pArbre existeFilsDroit(pArbre a){
    if(estVide(a)){
        printf("l'arbre est vide");
        return NULL;
    }
    if( a->fils_droit == NULL ){
        return 1;
    }
    else{
        return 0;
    }
}


pArbre ajouterFilsGauche(pArbre a, int e){
    
}



