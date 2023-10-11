#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Question 1 */

typedef struct chainon{
    int element;
    struct chainon * suivant;
}Chainon;


typedef struct filedyn{
    chainon * tete;
    chainon * queue;
    int taille;
}Filedyn;

Chainon * creerclient(){
    int x = (rand()%50)+1;
    Chainon * c = malloc(sizeof(Chainon));
    if(c == NULL){
        printf("erreur");
        exit(1);
    }
    c -> element = x;
    c -> suivant = NULL;
    return c;
}


/* Question 2 */

Piledyn * enfiler(Piledyn * ppile,int nb){
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

void afficheFile(Piledyn * pile){
    Piledyn * p = pile;
    while(p != NULL){
        printf("%d\n", p -> element);
        p = p -> suivant;
    }
}


void afficheFileRecursif(Piledyn * pile){
    if(pile != NULL){
        printf("%d\n", pile -> element);
        affichePileRecursif(pile -> suivant);
    }
}



Piledyn * defiler(Piledyn * pile, int * pnmb){
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
    Filedyn * nouvelle_pile = NULL;
    Filedyn * nouvelle_pile_pair = NULL;
    Filedyn * nouvelle_pile_impair = NULL;

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
    affichePile(nouvelle_pile_impair);


    /* Question 7 à l'aide d'une pile statique */

    return 0;
}