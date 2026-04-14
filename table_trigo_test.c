#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "table_trigo.h"

int main(){
    FILE *f ;
    f = ouvrir_fichier();
    test_ficher(f);
    generer_table_trigo(f);
    fermer_fichier(f);
    lire_ficher();
    return 0;
}