#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "exo2.h" 

/* 1 : CONSTRUCTION DE L'ARBRE */


parbre creerArbre(int a){                   // Question 1) c)
    parbre nouveau = malloc(sizeof(Arbre));
    if(nouveau == NULL){
        return NULL;
    }

    nouveau -> element = a;
    nouveau -> fils_droit = NULL;
    nouveau -> fils_gauche = NULL;
    return nouveau;
}

int estVide(parbre a){              // Question 1) d)
    if(a == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int estFeuille(parbre a){           // Question 1) e)
    if( (a->fils_droit == NULL) && (a->fils_gauche == NULL) ){
        return 1;
    }
    else{
        return 0;
    }
}

int element(parbre a){      // Question 1 f)
    if (a != NULL ){
        return a->element;
    }    
    else{
        return -1;
    }          
}


int existeFilsGauche(parbre a){    // Question 1) g)
    if(a == NULL){
        printf("l'arbre est vide");
        return 0;
    }
    else if( a->fils_gauche == NULL ){
        return 0;
    }
    else{
        return 1;
    }
}

int existeFilsDroit(parbre a){
    if(a == NULL){
        printf("l'arbre est vide");
        return 0;
    }
    else if( a->fils_droit == NULL ){
        return 0;
    }
    else{
        return 1;
    }
}


parbre ajouterFilsGauche(parbre a, int e){     // Question 1) h)
    parbre nouveau;
    if(existeFilsGauche(a)){
        return a;
    }
    nouveau = creerArbre(e);
    a->fils_gauche = nouveau;
    return a;
}

parbre ajouterFilsDroit(parbre a, int e){
    parbre nouveau;
    if(existeFilsDroit(a)){
        return a;
    }
    nouveau = creerArbre(e);
    a->fils_droit = nouveau;
    return a;
}


/* 2 : PARCOURS DE L'ARBRE */


File initfile(){  // parcour en largeur
    File f;
    f.tete=NULL;
    f.queue=NULL;
    return f;
}

void traiter(parbre arbre)        // Question 2) a)
{
    printf("%d ",arbre->element);
}


void parcourPrefixe(parbre arbre){          // Question 2) b)
    if(!estVide(arbre)){
        traiter(arbre);
        parcourPrefixe(arbre->fils_gauche);
        parcourPrefixe(arbre->fils_droit);
    }
}

void parcourInfixe(parbre arbre){
    if(!estVide(arbre)){
        parcourInfixe(arbre->fils_gauche);
        traiter(arbre);
        parcourInfixe(arbre->fils_droit);
    }
}

void parcourPostefixe(parbre arbre){       // Question 2) c)
    parbre noeud = arbre;
    if(!estVide(arbre)){
        parcourPostefixe(noeud->fils_gauche);
        parcourPostefixe(noeud->fils_droit);
        traiter(noeud);
    }
}

Chainon *creationchainon(parbre a){       // Question 2) d)
    Chainon *c = malloc(sizeof(Chainon));
    if(c==NULL){
        exit(1);
    }
    c->element=a;
    c->suivant=NULL;
    return c;
}


int verificationFile(File *file){
    int result=0;
    if(file==NULL){
        result=-1;
    }
    else if(((file->tete==NULL && file->queue != NULL) && (file->queue==NULL && file->tete != NULL))){
        result=-2;
    }
    else if(((file->queue) != NULL) && ((file->queue->suivant) != NULL)){
        result=-3;
    }
    return result;
}


int enfiler(File *file,parbre nb){
    Chainon *nouveau;
    int result = 0;
    result=verificationFile(file);
    if(result>-2){
        nouveau=creationchainon(nb);
        nouveau->suivant = NULL;
        if(file->queue==NULL){
            file->tete=nouveau;
            file->queue=nouveau;
        }
        else{
            file->queue->suivant=nouveau;
            file->queue=nouveau;
        }
    }
    return result;
}


int defiler(File *file, parbre *nb){
    Chainon * c= file->tete;
    int result=0;
    result=verificationFile(file);
    if(result==0){
        if(file->tete ==NULL && file->queue==NULL){
            result=1;
            printf("NULL");
        }
        if(file->tete == file->queue){
            *nb=file->tete->element;
            file->queue=NULL;
            file->tete=NULL;
            free(c);
        }
        else{
        *nb=file->tete->element;
        file->tete=file->tete->suivant;
        free(c);
        }
    }
    return result;
}



void parcourLargeur(parbre a){
    File nouveaufile=initfile();
    parbre noeud=a;
    if(!estVide(a)){
        enfiler(&nouveaufile,a);
        while(nouveaufile.queue!=NULL && nouveaufile.tete!=NULL){
            defiler(&nouveaufile,&noeud);
            traiter(noeud);
            if(existeFilsGauche(noeud)){
                enfiler(&nouveaufile,noeud->fils_gauche);
            } 
            if(existeFilsDroit(noeud)){
                enfiler(&nouveaufile,noeud->fils_droit);
            }
        }
    }
}


/* 3 : MODIFICATION DE L'ARBRE */


parbre modifierRacine(parbre a, int e){
    if(a == NULL ){
        exit(1);
    }
    else{
        a -> element = e;
    return a;
    }
}

void supprimerFilsGauche(parbre a) {
    if (a == NULL) {
        exit(1);
    } else if (existeFilsGauche(a)) {
        if (existeFilsGauche(a->fils_gauche)) {
            supprimerFilsGauche(a->fils_gauche);
        }
        if (existeFilsDroit(a->fils_gauche)) {
            supprimerFilsDroit(a->fils_gauche);
        }
        free(a->fils_gauche);
        a->fils_gauche = NULL; // Ajout pour éviter des problèmes potentiels
    }
}

void supprimerFilsDroit(parbre a) {
    if (a == NULL) {
        exit(1);
    } else if (existeFilsDroit(a)) {
        if (existeFilsGauche(a->fils_droit)) {
            supprimerFilsGauche(a->fils_droit);
        }
        if (existeFilsDroit(a->fils_droit)) {
            supprimerFilsDroit(a->fils_droit);
        }
        free(a->fils_droit);
        a->fils_droit = NULL; // Ajout pour éviter des problèmes potentiels
    }
}


parbre supprimerPos(parbre a, int valeur) {
    if (a == NULL) {
        return NULL;
    }

    if (a->element == valeur) {
        // Noeud trouvé, supprimer ce noeud
        // Cas 1 : Noeud sans fils
        if (a->fils_gauche == NULL && a->fils_droit == NULL) {
            free(a);
            return NULL;
        }
        // Cas 2 : Noeud avec un fils (gauche ou droit)
        else if (a->fils_gauche == NULL) {
            parbre temp = a->fils_droit;
            free(a);
            return temp;
        } else if (a->fils_droit == NULL) {
            parbre temp = a->fils_gauche;
            free(a);
            return temp;
        }
        // Cas 3 : Noeud avec deux fils
        else {
            parbre successeur = a->fils_droit;
            while (successeur->fils_gauche != NULL) {
                successeur = successeur->fils_gauche;
            }
            a->element = successeur->element;
            a->fils_droit = supprimerPos(a->fils_droit, successeur->element);
        }
    } else if (valeur < a->element) {
        a->fils_gauche = supprimerPos(a->fils_gauche, valeur);
    } else {
        a->fils_droit = supprimerPos(a->fils_droit, valeur);
    }

    return a;
}


int nmbfeuille(parbre a){
    if(a == NULL){
        return 0;
    }
    if(estFeuille(a)){
        return 1;
    }
    return nmbfeuille(a->fils_droit) + nmbfeuille(a->fils_gauche);
}

int taille(parbre a){
    if(a == NULL){
        return 0;
    }
    if(!(estFeuille(a))){
        return taille(a->fils_droit) + taille(a->fils_gauche);
    }
    return 1;
}

int hauteurarbre(parbre a){
    if(a == NULL){
        return -1;
    }
    else {
        int hauteurGauche = hauteur(a->fils_gauche);
        int hauteurDroit = hauteur(a->fils_droit);

        return 1 + max(hauteurGauche, hauteurDroit);
    }
}

int main(){

    parbre nouveau_arbre = creerArbre(1);       // Question 1) i)
    parbre noeud_suivant = nouveau_arbre;
    ajouterFilsDroit(nouveau_arbre,8);
    ajouterFilsGauche(nouveau_arbre,2);
    noeud_suivant = nouveau_arbre -> fils_gauche;
    ajouterFilsGauche(noeud_suivant,3);
    ajouterFilsDroit(noeud_suivant,6);
    noeud_suivant = noeud_suivant -> fils_gauche;
    ajouterFilsGauche(noeud_suivant,4);
    ajouterFilsDroit(noeud_suivant,5);
    noeud_suivant = nouveau_arbre -> fils_gauche;
    noeud_suivant = noeud_suivant -> fils_droit;
    ajouterFilsDroit(noeud_suivant,7);
    noeud_suivant = nouveau_arbre -> fils_droit;
    ajouterFilsDroit(noeud_suivant,10);
    ajouterFilsGauche(noeud_suivant,9);

    //parcourLargeur(nouveau_arbre);   // Question 2) f)
    //parcourPrefixe(nouveau_arbre);  // Question 2) c)
    //parcourInfixe(nouveau_arbre);
    //parcourPostefixe(nouveau_arbre);  // Question 2) d)

    //supprimerFilsGauche(nouveau_arbre);
    //supprimerPos(nouveau_arbre, 15);
    
    printf("%d ",nmbfeuille(nouveau_arbre));
    printf("\n");
    printf("%d ",taille(nouveau_arbre));
    printf("\n");
    parcourPrefixe(nouveau_arbre);
    return 0;
}
