#ifndef __VAISSEAU_H__
#define __VAISSEAU_H__
#include "affichage.h"
#include <stdio.h>

typedef enum {
    TOUCHE_AUCUNE = 0,
    TOUCHE_GAUCHE = 1,
    TOUCHE_DROITE = 2,
    TOUCHE_ESPACE = 3,
    TOUCHE_ESC = -1
} Touche;

// Permet de calculer le déplacement du sprite de l'utilisateur, tout en gardant le code plus lisible
void deplacement_sprite(int touche, int *x, int *y, int *largeur_sprite, int *largeur_fenetre);
// Permet d'afficher la touche sur laquelle on appuie, tout en gardant le code plus lisible
void affichage_touche_appuyer(int touche);

#endif