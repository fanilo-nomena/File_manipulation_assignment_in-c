#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "manipulation.h"

int main()
{
    int choix,n;
    char nom[20], nouveau_tel[20],recherche[20];
    FILE *f;
    do {
        printf("\n");
        printf("-----------MENU-------------\n");
        printf("1. Ajouter une personne\n");
        printf("2. Lire le fichier\n");
        printf("3. Rechercher par nom\n");
        printf("4. Modifier le numero de telephone\n");
        printf("5. Supprimer une personne\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        printf("\n");
        switch (choix) {

            case 1:
            f= ouvrir_ficher();
            fseek(f, 0, SEEK_END);
            if (ftell(f) == 0) {
                fprintf(f,"%10s %10s %20s %10s\n","Nom","Prenom","Telephone","Genre");
            }
            test_ficher(f);
            n = taille_table();
            entrer_table(f, n);
            fermer_ficher(f);
            break;
            printf("\n");

            case 2:
            lire_ficher();  
            break;
            case 3:
            printf("Entrer le nom a rechercher : ");
            scanf("%s", recherche);
            f = ouvrir_ficher();
            rechercher_par_nom(f, recherche);
            fermer_ficher(f);
            break;
            printf("\n");

            case 4:
            printf("Nom de la personne a modifier : ");
            scanf("%s", nom);
            printf("Nouveau numero : ");
            scanf("%s", nouveau_tel);
            f = ouvrir_ficher();
            modifier_telephone(f, nom, nouveau_tel);
            fermer_ficher(f);
            break;
            printf("\n");

            case 5:
            printf("Nom a supprimer : ");
            scanf("%s", nom);
            f = ouvrir_ficher();
            supprimer_personne(f, nom);
            fermer_ficher(f);
            break;
            printf("\n");
        }

    }

    while (choix != 0);
    return 0;
}