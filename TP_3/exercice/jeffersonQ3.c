// Commande gcc : 
//gcc -c cylindre.c && gcc -c jeffersonQ3.c && gcc cylindre.o jeffersonQ3.o -o launchQ3.out && ./launchQ3.out
/*

gcc -c cylindre.c
gcc -c jeffersonQ3.c
gcc cylindre.o jeffersonQ3.o -o launchQ3.out
./launchQ3.out 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "cylindre.h"

char tableau_2d[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE]= {0};

const char* fichier ="jefferson.txt";
int num_roue = 0;
#define TAILLE_TAB_CHAR_DECODE_MESSAGE 19
char caracteres_utilisateur[TAILLE_TAB_CHAR_DECODE_MESSAGE] ={0}; 
int main()
{
    // Affiche hello World
    printf("Hello world!\n");

    int test_ouverture_fichier = LitCylindre(fichier, tableau_2d);
    printf("\ntest_ouverture_fichier = %d (ouverture réussi) \n\n",test_ouverture_fichier);

    AfficherCylindre(tableau_2d);

    // Demande à l'utilisateur de rentré 19 caractère en minuscule
    printf("Taper 19 caracteres en minuscules\n");
    scanf("%19c",caracteres_utilisateur);
    printf("\n%s\n", caracteres_utilisateur);
    // Déchiffre le message codé de l'utilisateur
    for(int nbr_rot_necessaire = 0; nbr_rot_necessaire < TAILLE_TAB_CHAR_DECODE_MESSAGE; nbr_rot_necessaire++){
        
        int nbr_decalage = chercheLettreRoue(tableau_2d, nbr_rot_necessaire, caracteres_utilisateur[nbr_rot_necessaire]);
        tourneRoue(tableau_2d,nbr_decalage ,nbr_rot_necessaire);
    }

    return 0;
}
