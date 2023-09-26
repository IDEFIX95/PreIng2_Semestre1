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
    
    Chainon * nouvelle_liste = creationChainon();
}