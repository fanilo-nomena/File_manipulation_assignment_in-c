#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "manipulation.h"

// OUVRIR LE FICHER
FILE *ouvrir_ficher()
{
    FILE *f = fopen("manipulation_ficher.csv","a+");
    return f;
}

//TESTER SI LE FICHER EST OUVERT
bool test_ficher(FILE *f)
{
    if (f== NULL){
        printf("Erreur d'ouverture de ficher\n");
        return false;
    }
    printf("Ficher Ouvert avec succes\n");
    return true;
}

//TAILLE DE LA TABLE
int taille_table(){
    int n;
    printf("entrer le nombre de personne que vous voulez enregistrer :");
    scanf("%d",&n);
    return n;
}


// ENTRER LES DONNEES DANS LE FICHER
void entrer_table(FILE *f,int n){
    char nom[20], prenom[20];
    char telephone[20];
    char genre[10];
    for (int i=1; i<n; i++){
    printf("entrer le nom de la parsonne %d :", i);
    scanf("%10s", nom);
    printf("entrer le prenom de la parsonne %d :", i);
    scanf("%10s", prenom);
    printf("entrer le numero de telephone de la parsonne %d :", i);
    scanf("%20s", telephone);
    printf("entrer le genre de la parsonne %d :", i);
    scanf("%10s", genre);
    fprintf(f,"%10s %10s %20s %10s\n", nom, prenom, telephone, genre);
   }
}

// FERMER LE FICHER
void fermer_ficher(FILE *f){
    fclose(f);
}

// LIRE LE FICHER
void lire_ficher(){
   FILE *f= NULL;
   char chaine[400]= "";
   f = fopen("manipulation_ficher.csv","r");

   if (f == NULL){
    printf("Erreur d'ouverture de ficher \n");
    return;

   }
    while(fgets(chaine, 400, f) != NULL){
        printf("%s", chaine);// On lit le ficher tant qu'on ne reçoit pas d'erreur
    }
    fclose(f);
   
}

//RECHERCHER DES INFORMATIONS DANS LE FICHER A PARTIR DU NOM
bool rechercher_par_nom(FILE *f, const char *nom_recherche)
{
    FILE *f_recherche = fopen("manipulation_ficher.csv", "r");
    if (f_recherche == NULL)    {
        printf("Erreur d'ouverture du fichier pour la recherche\n");
        return false;
    }
    char nom[20], prenom[20];
    char telephone[20];
    char genre[10];

    rewind(f); 

    fscanf(f, "%*s %*s %*s %*s");

    while (fscanf(f, "%s %s %s %s", nom, prenom, telephone, genre) == 4)
    {
        if (strcmp(nom, nom_recherche) == 0)
        {
            printf("Trouvee : %s %s | Tel: %s | Genre: %s\n",
                   nom, prenom, telephone, genre);
            return true;
        }
    }

    printf("Personne non trouvee\n");
    return false;
    fclose(f_recherche);
}

//MODIFIER LE NUMERO DE TELEPHONE D'UNE PERSONNE A PARTIR DE SON NOM
void modifier_telephone(FILE *f, const char *nom_cible, const char *nouveau_tel)
{
    FILE *temp = fopen("temp.csv", "w");

    if (temp == NULL)
    {
        printf("Erreur fichier temporaire\n");
        return;
    }

    char nom[20], prenom[20], telephone[20], genre[10];
    int trouve = 0;

    rewind(f);

    fprintf(temp, "%10s %10s %20s %10s\n",
            "Nom", "Prenom", "Telephone", "Genre");

    fscanf(f, "%*s %*s %*s %*s");

    while (fscanf(f, "%s %s %s %s", nom, prenom, telephone, genre) == 4)
    {
        if (strcmp(nom, nom_cible) == 0)
        {
            fprintf(temp, "%10s %10s %20s %10s\n",
                    nom, prenom, nouveau_tel, genre);
            trouve = 1;
        }
        else
        {
            fprintf(temp, "%10s %10s %20s %10s\n",
                    nom, prenom, telephone, genre);
        }
    }

    fclose(temp);
    fclose(f);

    remove("manipulation_ficher.csv");
    rename("temp.csv", "manipulation_ficher.csv");

    if (trouve)
        printf("Modification reussie\n");
    else
        printf("Personne non trouvee\n");
}

// SUPPRIMER UNE PERSONNE A PARTIR DE SON NOM
void supprimer_personne(FILE *f, const char *nom_cible)
{
    FILE *temp = fopen("temp.csv", "w");

    if (temp == NULL)
    {
        printf("Erreur fichier temporaire\n");
        return;
    }

    char nom[20], prenom[20], telephone[20], genre[10];
    int trouve = 0;

    rewind(f);

    fprintf(temp, "%10s %10s %20s %10s\n",
            "Nom", "Prenom", "Telephone", "Genre");

    fscanf(f, "%*s %*s %*s %*s");

    while (fscanf(f, "%s %s %s %s", nom, prenom, telephone, genre) == 4)
    {
        if (strcmp(nom, nom_cible) == 0)
        {
            trouve = 1;
        }
        else
        {
            fprintf(temp, "%10s %10s %20s %10s\n",
                    nom, prenom, telephone, genre);
        }
    }

    fclose(temp);
    fclose(f);

    remove("manipulation_ficher.csv");
    rename("temp.csv", "manipulation_ficher.csv");

    if (trouve)
        printf("Suppression reussie\n");
    else
        printf("Personne non trouvee\n");
}