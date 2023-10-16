#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stddef.h>

# define MAX_TAILLE 100

typedef struct etudiant{
    char Nom[MAX_TAILLE];
    char Prenom[MAX_TAILLE];
    int groupes;
    int Notes[10];
    float moy;
    struct etudiant * suivant;
}Etudiant;

typedef struct lstetudiants{
    Etudiant * tete;
}LstEtudiants;


Etudiant * creation_etudiants(char nom[MAX_TAILLE], char prenom[MAX_TAILLE], int groupes, int Notes[10], float moy){
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
    nouveau_etudiant -> moy = moy;
    nouveau_etudiant->suivant = NULL;
    return nouveau_etudiant;
}

float moyTab(int * tab, size_t N){
    int somme = 0;
    for (size_t i = 0; i < N; i++)
    {
        somme += tab[i];
    }
    
    return (float)somme / N;
}

void trouveEtudiant(char * nom, char * prenom, LstEtudiants * lst){
    Etudiant * etudiant = lst->tete;
    int etudiant_trouver = 0;
    while (etudiant != NULL)
    {
        if (strcmp(etudiant->Nom, nom) == 0 && strcmp(etudiant->Prenom, prenom) == 0)
        {
            if (!etudiant_trouver) {
            printf("Voici les informations sur l'etudiant s'appelant %s %s\n", etudiant -> Prenom, etudiant -> Nom);
            etudiant_trouver = 1;
            }
        }
        etudiant = etudiant -> suivant;
    }
    if (!etudiant_trouver) {
        printf("\nAucun etudiant n'a été trouvé du Nom %s et Prenom %s\n",nom, prenom);
    }
}

void saisirEtudiant(LstEtudiants * lst){
    
    srand(time(NULL));
    char Nom[MAX_TAILLE];
    char Prenom[MAX_TAILLE];
    int groupes;
    int Notes[10];
    float moy;
    char demande_moy[5];
    

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

    printf("\n");

    printf("Voulez-vous avoir la moyen des notes des etudiants ? (O / N)\n");
    scanf("%s",demande_moy);
    if (strcmp(demande_moy, "O") == 0)
    {
        moy = moyTab(Notes,10);
    }
    else{
        moy = NAN;
    }

    
    
    Etudiant * nouveau_etudiant = creation_etudiants(Nom,Prenom,groupes,Notes,moy);

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
        printf("\nNom : %s ; Prenom : %s ; Groupe : %d ; Moy : %f ; Notes : ", etudiant->Nom, etudiant->Prenom, etudiant->groupes, etudiant->moy);
        for (int i = 0; i < 10; i++)
        {
            printf("%d ",etudiant->Notes[i]);
        }
        etudiant = etudiant->suivant;
        printf("\n");
    }
}

void listeParGroupe(LstEtudiants * lst, int groupe){
    Etudiant * etudiant = lst -> tete ; 
    int found = 0; // Variable pour vérifier si un étudiant du groupe a été trouvé
    while (etudiant != NULL)
    {
        if (etudiant -> groupes == groupe)
        {
            if (!found) {
                printf("\nVoici les Noms des etudiants qui se trouvent dans le numero de groupe suivant : %d \n", groupe);
                found = 1;
            }
            printf("Le Nom : %s \n",etudiant->Nom);
        }
        etudiant = etudiant -> suivant;
    }
    if (!found) {
        printf("\nAucun etudiant n'a été trouvé dans le groupe %d\n", groupe);
    }
}



int main(){
    char affichage_grp[5];
    char demande_recherche_etudiant[5];
    char Nom[20];
    char Prenom[20];
    int choix_numero_de_groupe;
    LstEtudiants * nouvelle_liste_etudiant = malloc(sizeof(LstEtudiants));
    nouvelle_liste_etudiant -> tete = NULL;
    //for (int i = 0; i < 2; i++)
    //{
        saisirEtudiant(nouvelle_liste_etudiant);
    //}

    printf("\n");

    printf("Voulez-vous faire une recherche sur un etudiant pour avoir toute ses informations ? (O / N)\n");
    scanf("%s",demande_recherche_etudiant);
    printf("\n");
    if (strcmp(demande_recherche_etudiant, "O") == 0)
    {
       printf("Veuillez selectionner le nom de l'etudiant dont vous voulez faire la recherche : \n");
       scanf("%s",Nom);
       printf("Veuillez selectionner le prenom de l'etudiant dont vous voulez faire la recherche : \n");
       scanf("%s",Prenom);
       trouveEtudiant(Nom,Prenom,nouvelle_liste_etudiant);
    }

    printf("\n");

    printf("Voulez-vous faire une recherche de groupes pour pouvoir voir les etudiants qui s'y trouve ? (veuillez taper soit O / N)\n");
    scanf("%s",affichage_grp);
    if (strcmp(affichage_grp, "O") == 0)
    {
        printf("Veuillez selectionner le numero de groupes que vous voulez voir : \n");
        scanf("%d",&choix_numero_de_groupe);
        listeParGroupe(nouvelle_liste_etudiant,choix_numero_de_groupe);
    }
    
    printf("\n");

    afficheListe(nouvelle_liste_etudiant);
    return 0;
}