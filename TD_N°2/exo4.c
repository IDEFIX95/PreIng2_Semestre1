#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Question 1 

        Reponse : une pile dynamique est le plus appropriée ici.

*/

typedef struct piledyn{
    char element;
    struct piledyn * suivant;
}Piledyn;

/* Question 2 */

Piledyn * empiler(Piledyn * ppile,char caracteres){
    Piledyn * nouveau = malloc(sizeof(Piledyn));
    if(nouveau == NULL){
        printf("erreur");
        exit(1);
    }
    nouveau -> element = caracteres;
    nouveau -> suivant = ppile;
    ppile = nouveau;
    return ppile;
}


void affichePile(Piledyn * pile){
    Piledyn * p = pile;
    while(p != NULL){
        printf("%c\n", p -> element);
        p = p -> suivant;
    }
}


void affichePileRecursif(Piledyn * pile){
    if(pile != NULL){
        printf("%d\n", pile -> element);
        affichePileRecursif(pile -> suivant);
    }
}



Piledyn * depile(Piledyn * pile, char * pnmb){
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
    
    Piledyn * nouvelle_pile = NULL;

    char formule_mathematique[100];
    printf("Veuillez saisir votre formule mathematique :\n");
    scanf("%s",formule_mathematique);
    int i;
     for (i = 0; i < strlen(formule_mathematique); i++) {
        if ((formule_mathematique[i] == '(' ) || (formule_mathematique[i] == '[' )) {
            nouvelle_pile = empiler(nouvelle_pile, formule_mathematique[i]);
        }
        else if(formule_mathematique[i] == ')'){
            if(nouvelle_pile == NULL || nouvelle_pile -> element != '('){
                printf("\nLe parenthésage est incorrect. La parenthèse fermante ou le crochet fermant sont apparues avant la parenthèse ouvrante ou le crochet ouvrant.\n");
                break;
            }
            else{ 
                char temp;
                nouvelle_pile = depile(nouvelle_pile, &temp);
            }
        }
        else if(formule_mathematique[i] == ']'){
            if (nouvelle_pile == NULL || nouvelle_pile -> element != '[')
            {
                printf("\nLe parenthésage est incorrect. Le crochet fermer est apparue avant le crochet ouvrant.\n");
                break;
            }
            else{ 
                char temp;
                nouvelle_pile = depile(nouvelle_pile, &temp);
            }
        }
       
    }

    if ((nouvelle_pile == NULL))
    {
        printf ("\nVotre formule mathematique a un bon parenthesage et/ou des crochets bien misent de facon correct.\n");

    }
    else{
        printf ("\nVotre formule mathematique a un mauvais parenthesages et/ou des crochets misent de facon incorrect.\n");
    }

    return 0;
}