#include "vaisseau.h"
// Définition du sprite du vaisseau
t_sprite vaisseau = {
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}
};

// Permet de calculer le déplacement du sprite de l'utilisateur, tout en gardant le code plus lisible
void deplacement_sprite(int touche, int *x, int *y, int *largeur_sprite, int *largeur_fenetre)
{
    if (touche == TOUCHE_GAUCHE)
    {
        *x -= 5;
    }
    if (touche == TOUCHE_DROITE)
    {
        *x += 5;
    }
    if (touche == TOUCHE_ESPACE)
    {
    }
    if (*x < 0)
    {
        *x = 0;
    }
    if (*x > *largeur_fenetre - *largeur_sprite)
    {
        *x = *largeur_fenetre - *largeur_sprite;
    }

    afficheSprite(vaisseau, *x, *y, ROUGE);
}

// Permet d'afficher la touche sur laquelle on appuie, tout en gardant le code plus lisible
void affichage_touche_appuyer(int touche)
{
    switch (touche)
    {

    case TOUCHE_GAUCHE:

        printf("Gauche\n");
        break;

    case TOUCHE_DROITE:

        printf("Droite\n");
        break;
    case TOUCHE_ESPACE:

        printf("Espace\n");
        break;

    case TOUCHE_ESC:

        printf("ESC\n");
        break;

    default:

        printf("Aucune\n");
        break;
    }
}
