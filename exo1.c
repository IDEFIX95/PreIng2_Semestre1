#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TAILLE 100

typedef struct date{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct lot{
    int numero_unique_lot;
    char texte_descriptif[MAX_TAILLE];
    Date * date;
    bool statut_produit;
    struct lot * suivant;
}Lot;

typedef struct listelot{
    Lot * tete;
}Listelot;


Lot * creationLot(int numero_unique_lot, char texte_descriptif[MAX_TAILLE], Date * date, bool statut_produit){
    Lot * nouveau_lot = malloc(sizeof(Lot));
    if(nouveau_lot == NULL){
        exit(1);
    }
    nouveau_lot -> numero_unique_lot = numero_unique_lot;
    strcpy(nouveau_lot -> texte_descriptif, texte_descriptif);
    nouveau_lot -> date = date;
    nouveau_lot -> statut_produit = statut_produit;
    return nouveau_lot;
}

void affichelisteproduit(Listelot * nouvelle_liste){
    Lot * nouveau_lot = nouvelle_liste -> tete;
    if(nouvelle_liste == NULL){
        printf("liste de lot vide");
        return;
    }

    while(nouveau_lot !=NULL){
        printf(" numero unique : %d ; texte descriptif : %s ; date : %d/%d/%d ; statut_produit : %s", nouveau_lot->numero_unique_lot, nouveau_lot -> texte_descriptif, nouveau_lot -> date->jour, nouveau_lot->date->mois,nouveau_lot->date->annee, nouveau_lot -> statut_produit ? "déjà cuisiné" : "non consommé");
        printf("\n");
        nouveau_lot = nouveau_lot -> suivant;
    }
    
}

void ajoutProduit(Listelot * nouvelle_liste, int numero_unique_lot, char texte_descriptif[MAX_TAILLE], Date * date, bool statut_produit) {
    Lot * nouveau_lot = malloc(sizeof(Lot));
    if (nouveau_lot == NULL) {
        exit(1);
    }
    nouveau_lot->numero_unique_lot = numero_unique_lot;
    strcpy(nouveau_lot->texte_descriptif, texte_descriptif);
    nouveau_lot->date = date;
    nouveau_lot->statut_produit = statut_produit;

    // Vérifier si la liste est vide
    if (nouvelle_liste->tete == NULL) {
        nouvelle_liste->tete = nouveau_lot;
        nouveau_lot->suivant = NULL;
        return;
    }

    // Vérifier si le numéro d'identification existe déjà dans la liste
    Lot * temp = nouvelle_liste->tete;
    while (temp != NULL) {
        if (temp->numero_unique_lot == numero_unique_lot) {
            printf("Erreur : le numéro de lot est déjà attribué.\n");
            exit(1);
        }
        temp = temp->suivant;
    }

    // Ajouter le nouveau lot au début de la liste
    nouveau_lot->suivant = nouvelle_liste->tete;
    nouvelle_liste->tete = nouveau_lot;
}


int main(){
    

    Listelot * nouvelle_liste = malloc(sizeof(Listelot));

    nouvelle_liste -> tete = NULL;

    for(int i =0 ; i<3; i++){
        srand(time(NULL));
        int numero_unique_lot = (rand()%100)+1;
        char texte_descriptif[MAX_TAILLE];

        printf("Veuillez selectionner le text descriptif du produit : \n");
        fgets(texte_descriptif, MAX_TAILLE, stdin);
        texte_descriptif[strcspn(texte_descriptif, "\n")] = 0; // supprime le retour à la ligne de la chaîne

        Date * date = malloc(sizeof(Date));

        if(date == NULL){
            exit(1);
        }

        printf("Veuillez selectionner la date :\n");
        printf("le jour : ");
        scanf("%d", &(date->jour));
        printf("le mois : ");
        scanf("%d",&(date->mois));
        printf("l'année : ");
        scanf("%d",&(date->annee));
        getchar(); // Nettoyer le tampon d'entrée
        

        bool statut_produit = false;
        /*if(!statut_produit){
            printf("%s",statut_produit_texte);
        }*/
        
            ajoutProduit(nouvelle_liste,numero_unique_lot,texte_descriptif,date,statut_produit);
    }

    affichelisteproduit(nouvelle_liste);

    return 0;
}