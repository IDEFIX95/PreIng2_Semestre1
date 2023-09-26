#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/* Question N° 1 */

typedef struct chainon{       
    int element;
    struct chainon * suivant;
} Chainon;


/* Question N° 2 */

Chainon * creationChainon(int a){
    Chainon * nouveau =malloc(sizeof(Chainon));
    if (nouveau == NULL){
        exit(1);
    }
    nouveau->element = a;
    nouveau->suivant = NULL;
    return nouveau;
}

/* Question N°3 */

/*
void insertDebut(Chainon ** pliste, int a){
    Chainon * nouveau_chainon = creationChainon(a);
    nouveau_chainon->suivant = *pliste;
    *pliste = nouveau_chainon;
}
*/

Chainon * insertDebut(Chainon * pliste, int a){
    Chainon * nouveau_chainon = creationChainon(a);
    nouveau_chainon->suivant = pliste;
    return nouveau_chainon;
}

/* Question N°4 */

Chainon * insertFin(Chainon * pliste, int a){
    Chainon * nouveau_chainon =creationChainon(a);
    Chainon * p1 = pliste;
    while(p1->suivant != NULL){
        p1 = p1 -> suivant;
    }
    p1-> suivant = nouveau_chainon;
    return pliste;
}


/* Question N°5 */

void afficheListe(Chainon * pliste){
    if(pliste==NULL){
		printf("Liste NULL");
	}
    while (pliste -> suivant != NULL){
        printf("%d->", pliste->element);
        pliste = pliste->suivant;
    }
    printf("%d", pliste->element);
}


 int main(){
    /* Question 6 */
    Chainon * new_chainon = NULL;

    /* Chainon * Depart = creationChainon(15);
    Depart = insertDebut(Depart, 9);
    insertFin(Depart, 25);
    afficheListe(Depart);
    */

    /* Question 7 */

    int taille;
    printf("Veuiller selectionner la taille de la liste : \n");
    scanf("%d", &taille);

    if (taille <= 0){
        printf("Veuillez selectinner une taille superieur à 0");
        return 1;
    }

    Chainon * liste = creationChainon(1); // On commence à 2^0 = 1
    Chainon * fin_liste = liste;

    for(int i = 1; i < taille; i++ ){
        printf("\nVoulez-vous avoir la puissance de deux suivante si oui taper 1 : ");
        int choix;
        scanf("%d",&choix);

        if(choix == 1){
            int nouvelle_puissance = (int)pow(2,i);
            fin_liste -> suivant = creationChainon(nouvelle_puissance);
            fin_liste = fin_liste->suivant;
            afficheListe(liste);
        }
        else{
            break;
        }
    }

    return 0; 
}