#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Question 1 :

    La reponse : Une structure qui ressemble à une File.

*/

typedef struct chainon{
    int element;
    struct chainon * suivant;
}Chainon;


typedef struct filedyn{
    Chainon * tete;
    Chainon * queue;
    int taille;
}Filedyn;

/* Fonction pour creer le client */

Chainon * creerclient(){
    int x = (rand()%50)+1;   // Nombre d'article
    Chainon * c = malloc(sizeof(Chainon));
    if(c == NULL){
        printf("erreur");
        exit(1);
    }
    c -> element = x;
    c -> suivant = NULL;
    return c;
}

int  filevide(Filedyn * pfile){
    if (pfile == NULL || (pfile->queue == NULL && pfile->tete == NULL)){
        return 1;
    }
    return 0;
}


Filedyn * Inserer_client(Filedyn * pfile){
    Chainon * nouveau = creerclient(); ;
    if(filevide(pfile)){
        pfile = malloc(sizeof(Filedyn));
        pfile -> queue = nouveau;
        pfile -> tete = nouveau;
        pfile -> taille = 1 ;
    }
    else{
        pfile -> queue -> suivant = nouveau;
        pfile -> queue = nouveau;
        pfile -> taille += 1 ;
    }
    return pfile;
}


Filedyn * Defiler_client(Filedyn * pfile, int * client){
    if(filevide(pfile)){
        printf("impossible d'enlever le client il n'existe pas car la file est vide");
        exit(1);
    }
    Filedyn * p = pfile;
    *client = p -> tete -> element;
    Chainon * temp = p -> tete;
    p -> tete = p -> tete -> suivant;
    free(temp);

    if(p -> tete == NULL){
        p->queue = NULL;
    }
    return p;
}


void affiche_client_passage(Filedyn * pClient,int *numero){
    if(filevide(pClient)){
        printf("\nimpossible d'afficher la file d'attente pour la caisse de auchan car il n'y a pas de client\n");
        exit(1);
    }
    
    Chainon * parcour = pClient -> tete;
    while(parcour != NULL){
        printf("\nLe Client Numero %d vient d'arriver à la caisse avec %d articles\n", *numero ,parcour -> element);
        parcour = parcour -> suivant;
        (*numero) +=1;
    }
}




int main() {

    srand(time(NULL));
    Filedyn * caisse_auchan = NULL;
    int client_enlever;
    int numero = 1;
    int numero_depiler = 1;
    for (int i = 0; i < 3; i++)
    {
        caisse_auchan = Inserer_client(caisse_auchan);
    }
    
    affiche_client_passage(caisse_auchan,&numero);
     
   while (!filevide(caisse_auchan))
    {
        
        if (filevide(caisse_auchan)) {
            printf("\nLa file d'attente est vide.\n");
            break;
        }
        caisse_auchan = Defiler_client(caisse_auchan, &client_enlever);        
        printf("\nLe Client Numero %d qui va passer et donc quitter la caisse de auchan : a %d articles\n", numero_depiler ,client_enlever);
        numero_depiler += 1;

        int ajouter_nouveau_client_pourcentage = (rand()%3) +1;
        int ajout_client_apres_pourcentage = (rand()%3) +1;
        ajout_client_apres_pourcentage = ajout_client_apres_pourcentage % 3 + 1;
        if (ajouter_nouveau_client_pourcentage == 1)
        {
            for (int i = 0; i < ajout_client_apres_pourcentage; i++)
            {
                caisse_auchan = Inserer_client(caisse_auchan);
            }
            affiche_client_passage(caisse_auchan,&numero);
        }
        
    }
    
    return 0;
}




/*void afficheFileRecursif(Piledyn * pile){
    if(pile != NULL){
        printf("%d\n", pile -> element);
        affichePileRecursif(pile -> suivant);
    }
}*/
