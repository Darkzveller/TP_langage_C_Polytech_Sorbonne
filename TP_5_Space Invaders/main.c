#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "affichage.h"
#include "alien.h"
#include "vaisseau.h"
/*

make mproper && make clean && make run

*/

#define NB_COLONNE 5
#define NB_LIGNE 3
#define ESPACEMENT_X_ALIEN 60 // espacement horizontal entre aliens
#define ESPACEMENT_Y_ALIEN 60 // espacement vertical entre rangées

int L = 400; // largeur fenêtre
int H = 600; // hauteur fenêtre

int main()
{
    if (initAffichage(L, H) != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de la fenêtre\n");
        return -1;
    }

    t_alien aliens[NB_LIGNE * NB_COLONNE];

    vaisseau.x = (L - 4 * SPRITE_X) / 2;
    vaisseau.y = H - 4 * SPRITE_Y - 10;

    initAlien(aliens, NB_LIGNE, NB_COLONNE, ESPACEMENT_X_ALIEN, ESPACEMENT_Y_ALIEN);

    int touche = 0; // Lecture de la touche appuyer

    // Boucle principale
    while (touche != TOUCHE_ESC)
    {
        // Déplacement et affichage des aliens
        for (int i = 0; i < NB_LIGNE * NB_COLONNE; i++)
        {
            deplaceAlien(&aliens[i]);
            afficheAlien(&aliens[i]);
        }

        // Déplacement du joueur
        deplaceVaisseau(&vaisseau, touche, L);

        // Rafraîchissement
        touche = miseAJourAffichage(50); // temporisation en µs
                                         // affichage_touche_appuyer(touche);
        int touche_allien = testMissile(&vaisseau, &aliens, NB_COLONNE * NB_LIGNE);
        if (touche_allien>0)
        {
            printf("Numéro alien touché : %d", touche_allien);
            printf("\n");
        }
    }

    return 0;
}
