#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>



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

Chainon * supDebut(Chainon * pliste){
    Chainon * nouveau_chainon = pliste;
    if (pliste != NULL){
        pliste = pliste->suivant;
        free(nouveau_chainon);
    }
    return pliste;
}

Chainon * supFin(Chainon * pliste){
    Chainon * nouveau_chainon = pliste;
    if(pliste == NULL){
        return NULL;
    }

    else if(pliste -> suivant == NULL){
        free(pliste);
        return NULL;
    }

    else{
        while (nouveau_chainon->suivant->suivant != NULL)
        {
            nouveau_chainon = nouveau_chainon->suivant;
        }
        free(nouveau_chainon->suivant);
        nouveau_chainon -> suivant = NULL;
    }
    return pliste;    
}

/* Question 2) a)*/
Chainon * sup1Element(Chainon * pliste, int valeur){
    Chainon * nouveau_chainon = pliste;
    Chainon * p2;
    if(pliste == NULL){
        return NULL;
    }

    if(pliste->element == valeur){
        pliste = supDebut(pliste);
        return pliste;
    }

    if (pliste -> suivant == NULL)
    {
        return pliste;
    }

    while(nouveau_chainon->suivant != NULL && nouveau_chainon->suivant->element != valeur){
            nouveau_chainon = nouveau_chainon -> suivant;
        }
    p2 = nouveau_chainon -> suivant;
    nouveau_chainon->suivant = p2->suivant;
    free(p2);   
    return pliste;
}

/* Question 2) b) */
Chainon * supToutElement(Chainon * pliste, int valeur){
    Chainon * nouveau_chainon = pliste;
    Chainon * p2;

    if(pliste == NULL){
        return NULL;
    }

    if (pliste -> suivant == NULL)
    {
        return pliste;
    }

    if(pliste->element == valeur){
        pliste = supDebut(pliste);
        return supToutElement(pliste, valeur);
    }

    while (nouveau_chainon -> suivant != NULL)
    {
        if(nouveau_chainon->suivant->element != valeur){
            nouveau_chainon = nouveau_chainon -> suivant;
        }
        else{
            p2 = nouveau_chainon -> suivant;
            nouveau_chainon -> suivant = p2 -> suivant;
            free(p2);
        }
    }
    return pliste;
}

int main(){
    /* Question 1 */
    srand(time(NULL));
    int valeur = rand()%6;
    Chainon * nouvelle_liste = creationChainon(valeur);
    Chainon * dernier_chainon = nouvelle_liste;
    for (int i = 0; i <9; i++)
    {
        int nouvelle_valeur = rand()%6;
        Chainon * nouveau_chainon = creationChainon(nouvelle_valeur);
        dernier_chainon ->suivant = nouveau_chainon;
        dernier_chainon = nouveau_chainon;
    }
    /* Question 2) c)*/
    printf("\nLa liste avant que la valeur saisie %d soit retirée de la liste\n", valeur);
    afficheListe(nouvelle_liste);
    printf("\n");
    printf("\nLa valeur supprimé sera %d\n", valeur);
    nouvelle_liste = supToutElement(nouvelle_liste, valeur);
    printf("\nVoici la liste avec la valeur supprimée\n");
    afficheListe(nouvelle_liste);
    return 0;
}