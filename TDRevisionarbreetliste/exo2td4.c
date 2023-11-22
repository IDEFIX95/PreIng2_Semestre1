#include <stdio.h>
#include <stdlib.h>

typedef struct arbre{
    int element;
    struct arbre * fg;
    struct arbre * fd;
}Arbre;

typedef Arbre * parbre;

parbre creationarbre(int valeur){
    parbre nouveau = malloc(sizeof(Arbre));
    nouveau -> element = valeur;
    nouveau -> fg = NULL;
    nouveau -> fd = NULL;
    return nouveau;
}

int estVide(parbre a){
    if(a == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int estFeuille(parbre a){
    if(a == NULL){
        exit(1);
    }
    else if(a->fg == NULL && a->fd == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int existeFilsGauche(parbre a){
    if(a == NULL){
        return 0;
    }
    else if(a->fg == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int existeFilsDroit(parbre a){
    if(a == NULL){
        return 0;
    }
    else if(a->fd == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

parbre ajouterFilsGauche(parbre a, int valeur){
    parbre nouveau;
    if(a == NULL){
        exit(1);
    }
    else if(!existeFilsGauche(a)){
        a->fg = nouveau;
    }
    return a;
}

parbre ajouterFilsDroit(parbre a, int valeur){
    parbre nouveau;
    if(a == NULL){
        exit(1);
    }
    else if(!existeFilsDroit(a)){
        a -> fd = nouveau;
    }
    return a;
}

parbre suppFilsGauche(parbre a){
    if(a == NULL){
        exit(1);
    }
    else if(existeFilsGauche(a)){
        if(existeFilsGauche(a->fg)){
            suppFilsGauche(a->fg)
        }
        if(existeFilsDroit(a->fg)){
            suppFilsDroit(a->fg);
        }
        free(a->fg);
        return a; 
    }
}

parbre suppFilsDroit(parbre a){
    if(a == NULL){
        exit(1);
    }
    else if(existeFilsDroit(a)){
        if(existeFilsDroit(a->fd)){
            suppFilsDroit(a->fd);
        }
        if(existeFilsGauche(a->fg)){
            suppFilsGauche(a->fg);
        }
        free(a->fd);
        return a;
    }
}

parbre modifierelement(parbre a, int valeur){
    if(a == NULL){
        exit(1);
    }
    else{
        a -> element = valeur;
    }
    return a;
}



int main(){
    return 0;
}