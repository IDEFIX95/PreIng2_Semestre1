#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct chainon{
    int element;
    struct chainon * suivant;
} Chainon;

Chainon * creationChainon(int a){
    Chainon * nouveau =malloc(sizeof(Chainon));
    if (nouveau == NULL){
        exit(1);
    }
    nouveau->element = a;
    nouveau->suivant = NULL;
    return nouveau;
}


void afficheListe(Chainon * pliste){
    if(pliste==NULL){
		printf("Liste NULL");
        return;
	}
    while (pliste -> suivant != NULL){
        printf("%d-> ", pliste->element);
        pliste = pliste->suivant;
    }
    printf("%d", pliste->element);
}




int main(){

    int taille;
    printf("\nVeuiller selectionner la taille de votre liste : ");
    scanf("%d", &taille);

    if(taille <= 0){
        printf("la taille de la liste doit etre superieure à zero.\n");
        return 1;
    }

    int element;
    printf("\nVeuillez selectionner un element ");
    scanf("%d", &element);

    Chainon * pliste = creationChainon(element);
    

    for(int i = 1; i < taille; i++){
        int nouveau_element;
        printf("\nVeuillez selectionner un nouveau element : ");
        scanf("%d", &nouveau_element);

        Chainon * changement_de_place = creationChainon(nouveau_element);

        if( nouveau_element <= pliste->element){
            changement_de_place -> suivant = pliste;
            pliste = changement_de_place;
        }
        else{
            Chainon * p1 = pliste;
            while(p1 -> suivant != NULL && p1 -> suivant -> element < changement_de_place -> element){
                p1 = p1 -> suivant;
            }
            changement_de_place -> suivant = p1 -> suivant; 
            p1 -> suivant = changement_de_place;
        }

        afficheListe(pliste);
    }
    return 0;
}