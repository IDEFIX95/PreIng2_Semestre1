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
        exit(1);
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
        exit(1);
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

/* parbre supp_noeud(parbre a, int e){
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
} */


int existeFilsGauche(parbre a){
    if(a == NULL){
        return 1;
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
        return 1;
    }
    else if(a->fd == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

parbre ajouterFilsGauche(parbre a, int valeur){
    parbre nouveau = creerarbre(valeur);
    if(a == NULL){
        exit(1);
    }
    else if(!existeFilsGauche(a)){
        a->fg = nouveau;
    }
    return a;
}

parbre ajouterFilsDroit(parbre a, int valeur){
    parbre nouveau = creerarbre(valeur);
    if(a == NULL){
        exit(1);
    }
    else if(!existeFilsDroit(a)){
        a->fd = nouveau;
    }
    return a;
}

void traiter(parbre arbre)        // Question 2) a)
{
    printf("%d ",arbre->element);
}

int estVide(parbre a){              // Question 1) d)
    if(a == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void parcourPrefixe(parbre arbre){          // Question 2) b)
    if(!estVide(arbre)){
        traiter(arbre);
        parcourPrefixe(arbre->fg);
        parcourPrefixe(arbre->fd);
    }
}

int main(){
    parbre nouveau_arbre = creerarbre(1);       // Question 1) i)
    parbre noeud_suivant = nouveau_arbre;
    ajouterFilsDroit(nouveau_arbre,8);
    ajouterFilsGauche(nouveau_arbre,2);
    noeud_suivant = nouveau_arbre -> fg;
    ajouterFilsGauche(noeud_suivant,3);
    ajouterFilsDroit(noeud_suivant,6);
    noeud_suivant = noeud_suivant -> fg;
    ajouterFilsGauche(noeud_suivant,4);
    ajouterFilsDroit(noeud_suivant,5);
    noeud_suivant = nouveau_arbre -> fg;
    noeud_suivant = noeud_suivant -> fd;
    ajouterFilsDroit(noeud_suivant,7);
    noeud_suivant = nouveau_arbre -> fd;
    ajouterFilsDroit(noeud_suivant,10);
    ajouterFilsGauche(noeud_suivant,9);
    parcourPrefixe(nouveau_arbre);
    return 0;
}
