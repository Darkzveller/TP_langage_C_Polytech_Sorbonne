#ifndef _CYLINDRE_H
#define _CYLINDRE_H
/*
Mauvaise compréhension du sujet, la valeur de la colonne équivaut a celle de la ligne et inversement.
Laisser actuellement dans l'état faute de temps. La problematique a été résolu, dans la fonction LitCylindre,
ou il a juste fallu inverser le for qui lit sur la ligne et sur la colonne.
*/
#define TAILLE_TABLEAU_COLONNE 19
#define TAILLE_TABLEAU_LIGNE 26

//--------------------------- QUESTION 1 ---------------------------
// Fonction permettant d'ouvrir un fichier txt, avec une suite de caractère, et l'écrit dans un tableau de 2 dimension
int LitCylindre(const char* nom_fichier, char tab_remplir[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE]);
// Affiche le tableau de dimension écrit a partir des données trouvés dans le fichier .txt
void AfficherCylindre(char tab_afficher[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE]);  

//--------------------------- QUESTION 2 ---------------------------
// Permet de chercher une lettre dans une roue spécifique 
int chercheLettreRoue(char tab_representant_cylindre[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE], int num_roue, char lettre_rechercher);
// Permet de tourner la roue de c valeur
void tourneRoue(char cylindre[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE], int nbr_decalage_haut, int num_roue);

#endif