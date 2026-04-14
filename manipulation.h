FILE *ouvrir_ficher();
bool test_ficher(FILE *f);
int taille_table();
void entrer_table(FILE *f,int n);
void fermer_ficher(FILE *f);
void lire_ficher();
bool rechercher_par_nom(FILE *f, const char *nom_recherche);
void modifier_telephone(FILE *f, const char *nom_cible, const char *nouveau_tel);
void supprimer_personne(FILE *f, const char *nom_cible);