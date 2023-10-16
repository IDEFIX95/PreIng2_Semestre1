#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

# define MAX_TAILLE 100

typedef struct etudiant{
    char Nom[MAX_TAILLE];
    char Prenom[MAX_TAILLE];
    int groupes;
    int Notes[10];
    struct etudiant * suivant;
}Etudiant;

typedef struct lstetudiants{
    Etudiant * tete;
}LstEtudiants;


Etudiant * creation_etudiants(char nom[MAX_TAILLE], char prenom[MAX_TAILLE], int groupes, int Notes[10]){
    Etudiant * nouveau_etudiant = malloc(sizeof(Etudiant));
    if (nouveau_etudiant == NULL){
        exit(1);
    }
    strcpy(nouveau_etudiant->Nom, nom);
    strcpy(nouveau_etudiant->Prenom, prenom);
    nouveau_etudiant->groupes = groupes;
    for (int i = 0; i < 10; i++)
    {
        nouveau_etudiant->Notes[i] = Notes[i];
    }
    nouveau_etudiant->suivant = NULL;
    return nouveau_etudiant;
}

void saisirEtudiant(LstEtudiants * lst){
    
    srand(time(NULL));
    char Nom[MAX_TAILLE];
    char Prenom[MAX_TAILLE];
    int groupes;
    int Notes[10];

    printf("Veuillez saisir le Nom de l'etudiant : ");
    scanf("%s",Nom);
    printf("Veuillez saisir le prenom de l'etudiant : ");
    scanf("%s", Prenom);
    printf("Veuillez saisir le groupe de l'etudiant : ");
    scanf("%d", &groupes);

    printf("\n");

    for (int i = 0; i <10; i++)
    {
        int notes_aleatoire = rand()%21;
        Notes[i] = notes_aleatoire;
    }
    
    Etudiant * nouveau_etudiant = creation_etudiants(Nom,Prenom,groupes,Notes);

    if(lst -> tete == NULL){
        lst->tete = nouveau_etudiant;
    }
    else{
        Etudiant * temp = lst->tete;
        while (temp -> suivant != NULL)
        {
            temp = temp -> suivant;
        }
        temp->suivant = nouveau_etudiant;
    }
}


void afficheListe(LstEtudiants * etudiant_liste){
    Etudiant * etudiant = etudiant_liste -> tete ;
    if(etudiant_liste==NULL){
		printf("Liste des etudiants vide");
        return;
	}
    while (etudiant != NULL){
        printf("\nNom : %s ; Prenom : %s ; Groupe : %d ; Notes : ", etudiant->Nom, etudiant->Prenom, etudiant->groupes);
        for (int i = 0; i < 10; i++)
        {
            printf("%d ",etudiant->Notes[i]);
        }
        etudiant = etudiant->suivant;
        printf("\n");
    }
}
/* 
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
}*/



int main(){
    
    LstEtudiants * nouvelle_liste_etudiant = malloc(sizeof(LstEtudiants));
    nouvelle_liste_etudiant -> tete = NULL;
    for (int i = 0; i < 2; i++)
    {
        saisirEtudiant(nouvelle_liste_etudiant);
    }
    
    afficheListe(nouvelle_liste_etudiant);

    return 0;
}