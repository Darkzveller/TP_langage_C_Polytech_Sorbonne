// Commande gcc : 
//gcc -c cylindre.c && gcc -c jeffersonQ2.c && gcc cylindre.o jeffersonQ2.o -o launchQ2.out && ./launchQ2.out
/*

gcc -c cylindre.c
gcc -c jeffersonQ2.c
gcc cylindre.o jeffersonQ2.o -o launchQ2.out
./launchQ2.out 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "cylindre.h"

char tableau_2d[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE]= {0};

const char* fichier ="jefferson.txt";
int num_roue = 0;

int main()
{
    // Affiche hello World
    printf("Hello world!\n");
    //Si renvoie 1, le fichier a été ouvert avec succès
    int test_ouverture_fichier = LitCylindre(fichier, tableau_2d);
    printf("\ntest_ouverture_fichier = %d (ouverture réussi) \n\n",test_ouverture_fichier);

    AfficherCylindre(tableau_2d);


    tourneRoue(tableau_2d, chercheLettreRoue(tableau_2d, num_roue, 'p'),num_roue);

    return 0;
}
