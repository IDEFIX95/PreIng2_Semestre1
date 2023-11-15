#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* 1 : CONSTRUCTION DE L'ARBRE */

typedef struct arbre{           // Question 1) a)
    int element;
    struct arbre * fils_gauche;
    struct arbre * fils_droit;
}Arbre;

typedef Arbre * parbre;         // Question 1) b)



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

typedef struct chainon{
    parbre element;
    struct chainon* suivant;
}Chainon;


typedef struct file{  // Fait parti de la question sur les parcours (ici parcour en largeur)  Question 2) d)
    Chainon  *queue;
    Chainon  *tete;
}File;


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
    a -> element = e;
    return a;
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
    return 0;
}