#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "table_trigo.h"

FILE *ouvrir_fichier()
{
    FILE *f = fopen("table_trigonometrique.csv", "w");
    return f;
}

bool test_ficher(FILE *f)
{
    if (f == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return false;
    }

    printf("Fichier ouvert avec succes\n");
    return true;
}

void generer_table_trigo(FILE *f){
    int i;
    fprintf(f, "Angle\tSin\tCos\tTan\n");

    for (i =0; i<=360; i++){
        double radian, valeur_sin, valeur_cos, valeur_tan;
         radian = i * M_PI / 180.0; 
         if(valeur_cos != 0){
            valeur_tan = valeur_sin / valeur_cos;
        } else {
            valeur_tan = 0;
        }
         valeur_sin = sin(radian);
         valeur_cos = cos(radian);
         valeur_tan = tan(radian);  
            fprintf(f, "%d\t%.2f\t%.2f\t%.2f\n", i, valeur_sin, valeur_cos, valeur_tan);
    } 
}

void fermer_fichier(FILE *f){
    fclose(f);
}

void lire_ficher(){
   FILE *f= NULL;
   char chaine[400]= "";
   f = fopen("table_trigonometrique.csv", "r");

   if (f == NULL){
    printf("Erreur d'ouverture de ficher \n");
    return;

   }
    while(fgets(chaine, 400, f) != NULL){
        printf("%s", chaine);// On lit le ficher tant qu'on ne reçoit pas d'erreur
    }
    fclose(f);
   
}

