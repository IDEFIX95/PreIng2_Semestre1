#include <stdio.h>
#include <stdlib.h>


#define MAX_TAILLE 100

typedef struct pilestat{
    int  tabPile[MAX_TAILLE];
    int taille;
    int tete;
}Pilestat;


Pilestat * creationPilestat(){
    Pilestat * pile = malloc(sizeof(Pilestat));
    pile -> tete = -1;
    pile -> taille = MAX_TAILLE;
    return pile;
}

int verificationPilestat(Pilestat * pile){
    int result = 0;
    if(pile == NULL){
        result = -1;
    }
    else if ( (pile -> taille  < 0) || (pile -> tete < -1) || (pile -> tete > (pile->taille)-1 )){
        result = -2;
    }
    return result;
}

/* A revoir */

int empilagePilestat(Pilestat * pile, int element){
    int result = 0;
    result = verificationPilestat(pile);
    //printf("Avant l'ajout : result = %d, tete = %d\n", result, pile->tete); // Sortie de débogage
    if(result == 0){
        if(pile->tete == (pile->taille)-1){
            result = -1;
        }
        else{
            pile->tete = pile->tete + 1;
            pile->tabPile[pile->tete] = element;
        }
    }
    //printf("Après l'ajout : result = %d, tete = %d\n", result, pile->tete); // Sortie de débogage
    return result;
}

int depillagePileStat(Pilestat * pile, int * element){
    int result = 0;
    result = verificationPilestat(pile);
    if(element == NULL){
        result = -1;
    }
    if(result == 0){
        if(pile -> tete == -1){
            result = 1;
        }
        else{
            *element = pile -> tabPile[pile->tete];
            pile -> tete = pile -> tete - 1;
        }
    }
    return result;
}



void affichePile(Pilestat * pile){
    for(int i=0; i<=pile->tete;i++){
        printf("%d\n",pile->tabPile[i]);
    }
}



int main() {
    /* Question 7 à l'aide d'une pile statique */

    Pilestat * nouvelle_pile_stat = creationPilestat();
    Pilestat * nouvelle_pile_stat_pair = creationPilestat();
    Pilestat * nouvelle_pile_stat_impair = creationPilestat();

    for (int i = 20; i > 0; i--) {
        empilagePilestat(nouvelle_pile_stat, i);
    }
    affichePile(nouvelle_pile_stat);

    printf("\n \n");

    int valeur;

    while(nouvelle_pile_stat->tete > -1){
        depillagePileStat(nouvelle_pile_stat,&valeur);
        if (valeur % 2 == 0) {
            empilagePilestat(nouvelle_pile_stat_pair, valeur);
        } else {
            empilagePilestat(nouvelle_pile_stat_impair, valeur);
        }
    }
    

    printf("Nouvelle pile des éléments pairs :\n");
    affichePile(nouvelle_pile_stat_pair);

    printf("\n\n");

    printf("Nouvelle pile des éléments impairs :\n");
    affichePile(nouvelle_pile_stat_impair);

    return 0;
}