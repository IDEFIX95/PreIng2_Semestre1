#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
    int element;
    struct arbre * fg;
    struct arbre * fd;
}Arbre;

typedef Arbre * parbre;

parbre creerarbre(int valeur){
    parbre nouveau = malloc(sizeof(Arbre));
    nouveau -> element = valeur;
    nouveau -> fg = NULL;
    nouveau -> fd = NULL;
    return nouveau;
}

int recherche(parbre a, int e){
    if(a == NULL){
        return 1;
    }
    else if(a->element = e){
        return 0;
    }
    else if(a->element > e){
        return recherche(a->fg,e);
    }
    else {
        return recherche(a->fd,e);
    }
}

parbre insertABR(parbre a, int e){
    if(a == NULL){
        return 1;
    }
    if(a->element > e){
        a->fg = insertABR(a->fg, e);
    }
    else{
        a->fd = insertABR(a->fd, e);
    }
    return a;
}

parbre insertABR2(parbre a, int e){
    if(a == NULL){
        return 1;
    }
    parbre nouveau = creerarbre(e);
    if(a->element > nouveau -> element){
        a->fg = nouveau;
    }
    else{
        a->fd = nouveau;
    }
    return a;
}

parbre supp_noeud(parbre a, int e){
    parbre tmp;
    if(a == NULL){
        return a;
    }
    else if(a->element < e){
        a->fd = supp_noeud(a->fd, e);
    }
    else if(a->element > e){
        a->fg = supp_noeud(a->fg, e);
    }
    else if(!existeFilsGauche(a)){
        tmp = a->element;
        a = a->fd;
        free(tmp);
    }

    else{
        a->fg = supp_Max(a->fg, &(a->element));
    }
    return a;
}


parbre supp_Max(parbre a, int * e){
    parbre p1;
    if(existeFilsDroit(a)){
        a->fd = supp_Max(a->fd,e);
    }
    else {
        *e = a->element;
        p1 = a;
        a = a->fg;
        free(p1);
    }
    return a;
}


int existeFilsGauche(parbre a){
    if(a == NULL){
        return 1;
    }
    else if(a->fg != NULL){
        return 0;
    }
    else{
        return 1;
    }
}


int main(){
    return 0;
}