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

Chainon * insertFin(Chainon * pliste, int a){
    Chainon * nouveau_chainon =creationChainon(a);
    Chainon * p1 = pliste;
    while(p1->suivant != NULL){
        p1 = p1 -> suivant;
    }
    p1-> suivant = nouveau_chainon;
    p1 = nouveau_chainon;
    return pliste;
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
    for (int i = 0; i <9; i++)
    {
        int nouvelle_valeur = rand()%6;
        nouvelle_liste = insertFin(nouvelle_liste,nouvelle_valeur);
    }
    afficheListe(nouvelle_liste);
    printf("\n");
    Chainon * new_liste = NULL;
    new_liste = inversionListe(nouvelle_liste,new_liste);
    afficheListe(new_liste);
    return 0;
}