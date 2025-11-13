// Commande gcc : 
//gcc -c cylindre.c && gcc -c jeffersonQ1.c && gcc cylindre.o jeffersonQ1.o -o launch.out && ./launch.out
/*

gcc -c cylindre.c
gcc -c jeffersonQ1.c
gcc cylindre.o jeffersonQ1.o -o launch.out
./launch.out 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "cylindre.h"

char tableau_2d[TAILLE_TABLEAU_LIGNE][TAILLE_TABLEAU_COLONNE]= {0};

const char* fichier ="jefferson.txt";

int main()
{
    // Affiche hello World
    printf("Hello world!\n");
    //Si renvoie 1, le fichier a été ouvert avec succès
    int test_ouverture_fichier = LitCylindre(fichier, tableau_2d);
    printf("\ntest_ouverture_fichier = %d (ouverture réussi) \n\n",test_ouverture_fichier);

    AfficherCylindre(tableau_2d);

    return 0;
}
