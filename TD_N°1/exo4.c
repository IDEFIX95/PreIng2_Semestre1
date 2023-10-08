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

Chainon * insertDebut(Chainon * pliste, int a){
    Chainon * nouveau_chainon = creationChainon(a);
    nouveau_chainon->suivant = pliste;
    return nouveau_chainon;
}

Chainon * inversionListe(Chainon * pliste1, Chainon * pliste2){
    Chainon * p1 = pliste1;
    while (p1 != NULL)
    {
        pliste2 = insertDebut(pliste2,p1->element);
        p1 = p1 -> suivant;
    }
    return pliste2;
}

Chainon * inverse2(Chainon * pliste){ // version sans decompte
    Chainon * p1;
    Chainon * p2;
    if(pliste == NULL){
        return pliste;
    }

    p1 = pliste ->suivant;
    pliste -> suivant = NULL;
    while(p1){
        p2 = p1 ->suivant;
        p1 ->suivant = pliste;
        pliste = p1;
        p1 = p2;
    }
    return pliste;
}

int main(){
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
    afficheListe(nouvelle_liste);
    printf("\n");
    Chainon * new_liste = NULL;
    new_liste = inversionListe(nouvelle_liste,new_liste);
    afficheListe(new_liste);
    return 0;
}