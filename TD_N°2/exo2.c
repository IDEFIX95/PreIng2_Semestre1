#include <stdio.h>
#include <stdlib.h>


#define MAX_TAILLE 100

/* Question 1 */

typedef struct piledyn{
    int element;
    struct piledyn * suivant;
}Piledyn;

typedef struct pilestat{
    struct  tabPile[MAX_TAILLE];
    int taille;
    int tete;
}Pilestat;


Pilestat * creationPilestat(){
    Pilestat * pile;
    pile -> tete = -1;
    return pile;
}

int verificationPilestat(Pilestat * pile){
    int result = 0;
    if(pile == NULL){
        result = -1;
    }
    else if ((pile -> taille  < 0) || (pile- > tete < -1) || (pile -> tete > (pile->taille)-1 )){
        result = -2;
    }
    return result;
}

/* A revoir */

int empilagePilestat(Pilestat * pile, int element){
    int result = 0;
    result = verificationPilestat(pile);
    if(result == 0){
        if(pile->tete == (pile->taille)-1){
            result = -1;
        }
        else{
            pile->tete = pile->tete + 1;
            pile->tabPile[tete] = element;
        }
    }
    return result;
}

int depillagePileStat(Pilestat * pile, int * element){
    int result = 0;
    result = verificationPilestat(pile);
    if(element == NULL){
        result = -1;
    }
    if(result = 0){
        if(pile -> tete = -1){
            
        }
    }
}
/* Question 2 */

Piledyn * empiler(Piledyn * ppile,int nb){
    Piledyn * nouveau = malloc(sizeof(Piledyn));
    if(nouveau == NULL){
        printf("erreur");
        exit(1);
    }
    nouveau -> element = nb;
    nouveau -> suivant = ppile;
    ppile = nouveau;
    return ppile;
}


void affichePile(Piledyn * pile){
    Piledyn * p = pile;
    while(p != NULL){
        printf("%d\n", p -> element);
        p = p -> suivant;
    }
}


void affichePileRecursif(Piledyn * pile){
    if(pile != NULL){
        printf("%d\n", pile -> element);
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


int main() {
    /* Suite Question 2 */

    /* Fait à l'aide d'une pile dynamique */
    /* Piledyn * nouvelle_pile = NULL;
    Piledyn * nouvelle_pile_pair = NULL;
    Piledyn * nouvelle_pile_impair = NULL;

    for (int i = 1; i < 21; i++) {
        nouvelle_pile = empiler(nouvelle_pile, i);
    }
    affichePile(nouvelle_pile);

    printf("\n\n");


    int valeur;
    
    while (nouvelle_pile != NULL) {
        nouvelle_pile = depile(nouvelle_pile, &valeur);
        if (valeur % 2 == 0) {
            nouvelle_pile_pair = empiler(nouvelle_pile_pair, valeur);
        } else {
            nouvelle_pile_impair = empiler(nouvelle_pile_impair, valeur);
        }
    }

    printf("Nouvelle pile des éléments pairs :\n");
    affichePile(nouvelle_pile_pair);

    printf("\n\n");

    printf("Nouvelle pile des éléments impairs :\n");
    affichePile(nouvelle_pile_impair);*/


    /* Question 7 à l'aide d'une pile statique */

    Pilestat* nouvelle_pile_stat = NULL;
    Pilestat * nouvelle_pile_pair = NULL;
    Pilestat * nouvelle_pile_impair = NULL;

    for (int i = 1; i < 21; i++) {
        nouvelle_pile_stat = empilerstat(nouvelle_pile_stat, i);
    }
    affichePile(nouvelle_pile_stat);

    return 0;
}