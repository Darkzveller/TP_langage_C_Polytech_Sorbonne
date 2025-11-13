#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "cylindre.h"
//--------------------------- QUESTION 1 ---------------------------
/*La fonction LitCylindre, prend en entrée : 
- Le nom du fichier + son type en char, par exemple si le fichier jsp et que son type est du texte, on écrira "jsp.txt"
- Le tableau qu'on souhaite remplir,

Déroulement de la fonction : 
- Ouvre le fichier
- Vérifie si l'ouverture s'est bien passé
- Lit les valeurs contenu dans le fichier, et le rempli dans le tableau de taille m*n
- Ferme le fichier ouvert
*/

int LitCylindre(const char* nom_fichier, char tab_remplir[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE]){

    int reussite_ouverture_fichier =0;
    FILE *fp = fopen(nom_fichier, "r");

    // Vérifie qu'on a bien ouvert le fihcier valeurs.txt
    if (fp == NULL)
    {
        printf("Le fichier grille.txt n'a pas pu être ouvert\n");
        reussite_ouverture_fichier = 0;
        //return EXIT_FAILURE;
    }else{
        reussite_ouverture_fichier = 1;
    }

    printf("Le fichier ");
    printf("%s",nom_fichier);
    printf(" existe \n ");

  
        for (int colonne =0; colonne<TAILLE_TABLEAU_COLONNE; colonne++){
              for(int ligne =0; ligne<TAILLE_TABLEAU_LIGNE;ligne++){
                fscanf(fp, "%c", &(tab_remplir[ligne][colonne]));

        }
    }
    
    fclose(fp);
}
/*La fonction AfficheCylindre, prend en entrée : 
- Le tableau représentant la table de jefferson sur une taille en 2 dimensions,

Déroulement de la fonction : 
- Affiche un message, pour avertir de ce qu'on voit
- Itération permettant de mettre en forme et afficher le tableau de jefferson 
*/
void AfficherCylindre(char tab_afficher[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE]){   
    printf("Le cylindre lu est ce qu'on voit ci dessous\n");
    /*
    for(int ligne =0; ligne<TAILLE_TABLEAU_LIGNE;ligne++){
        printf("Ligne %d : ",ligne);
        for (int colonne =0; colonne<TAILLE_TABLEAU_COLONNE; colonne++){
            printf("%c",tab_afficher[ligne][colonne]);

        }
        printf("\n");
    }
    */
    for(int ligne  =0; ligne<TAILLE_TABLEAU_LIGNE;ligne++){
    printf("-----------------------------------------------------------------------------\n");
        for (int colonne =0; colonne<TAILLE_TABLEAU_COLONNE; colonne++){
            printf("| %c ",tab_afficher[ligne][colonne]);

        }
        printf("|\n");
    }
    printf("-----------------------------------------------------------------------------\n");

}

//--------------------------- QUESTION 2 ---------------------------

/*La fonction chercheLettreRoue, prend en entrée : 
- Le tableau représentant la table de jefferson sur une taille en 2 dimensions,
- Le numéro de la roue sur laquelle on souhaite travaillé
- La lettre qu'on recherche au sein de cette roue

Déroulement de la fonction : 
- Créer un entier nommé lettre_renvoyé, qui renvoie la ligne à laquelle on a trouvé notre lettre
- Itération permettant de chercher notre lettre dans la roue sélectionner 
- Affiche pour l'utilisateur, la lettre trouvé ainsi que ces coordonnées
- Return le numero de la ligne ou on a retrouvé notre lettre
*/

int chercheLettreRoue(char tab_representant_cylindre[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE], int num_roue, char lettre_rechercher){
    int lettre_renvoyer =0;
    for (int ligne =0; ligne<TAILLE_TABLEAU_LIGNE; ligne++){

        if(tab_representant_cylindre[ligne][num_roue] == lettre_rechercher){

            printf("La lettre %c a été trouvé a la ligne %d\n", lettre_rechercher, ligne);
            lettre_renvoyer= ligne;
        }

    }
return lettre_renvoyer;
}

/*
La fonction tourneRoue, prend en entrée : 
- Le tableau qu'on souhaite modifier de taille 2,
- De combien on souhaite faire tourné la roue vers le haut
- Le numéro de la roue sur laquelle on souhaite travaillé

Déroulement de la fonction : 
- Créer un tableau de char nommé tab_intermediaire de dimension
- Itération permettant de remplir notre tableau sur une dimension 
- Itération permettant de faire le décalage au niveau de la roue
- Affiche le tableau modifier, permettant de vérifier si le code l'a bien modifier
*/

void tourneRoue(char tab_representant_cylindre[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE], int nbr_decalage_haut, int num_roue) {
    
    char tab_intermediaire[TAILLE_TABLEAU_LIGNE];

    // On copie la roue à la colonne x dans un tableau 1D temporaire
    for (int ligne = 0; ligne < TAILLE_TABLEAU_LIGNE; ligne++) {
        tab_intermediaire[ligne] = tab_representant_cylindre[ligne][num_roue];
    }

    // On effectue le décalage de la colonne x vers le haut
    for (int ligne = 0; ligne < TAILLE_TABLEAU_LIGNE; ligne++) {
        tab_representant_cylindre[ligne][num_roue] = tab_intermediaire[(ligne + nbr_decalage_haut) % TAILLE_TABLEAU_LIGNE];
    }

    // Affichage du cylindre après rotation
    printf("Le cylindre après rotation de la roue %d vers le haut de %d lettres :\n", num_roue, nbr_decalage_haut);
    for (int ligne = 0; ligne < TAILLE_TABLEAU_LIGNE; ligne++) {
        printf("-----------------------------------------------------------------------------\n");
        for (int colonne = 0; colonne < TAILLE_TABLEAU_COLONNE; colonne++) {
            printf("| %c ", tab_representant_cylindre[ligne][colonne]);
        }
        printf("|\n");
    }
    printf("-----------------------------------------------------------------------------\n");
}


