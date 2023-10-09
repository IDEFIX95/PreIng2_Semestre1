#include <stdio.h>
#include <stdlib.h>


/* Question 1 */

typedef struct piledyn{
    int element;
    struct piledyn * suivant;
}Piledyn;



/* Question 2 */

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
    while(p != NULL){
        printf("%d\n", p ->element);
        p = p -> suivant;
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


Piledyn * pilepair(Piledyn * pile){
    Piledyn * p1 = pile;
    Piledyn * pile_pair = NULL;
    while(p1 != NULL)
    {
        if(p1->element % 2 == 0){
          pile_pair = empiler(pile_pair, p1->element);
        }
        p1=p1->suivant;
    }
    return pile_pair;
}


Piledyn * pileimpair(Piledyn * pile){

}

int main() {
    /* Suite Question 2 */
    Piledyn * nouvelle_pile = NULL;
    Piledyn * nouvelle_pile_pair = NULL;
    Piledyn * nouvelle_pile_impair = NULL;

    for (int i = 1; i < 21; i++) {
        nouvelle_pile = empiler(nouvelle_pile, i);
    }
    affichePile(nouvelle_pile);

    printf("\n\n");


    /* Question 6 */
    while (nouvelle_pile != NULL) {
        int valeur;
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

    return 0;
}