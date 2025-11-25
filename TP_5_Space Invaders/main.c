#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>  
#include "affichage.h"
#include "alien.h"

/*

make mproper && make clean && make run



*/
void deplacement_sprite(int touche, int *x, int *y, int *largeur_sprite, int *largeur_fenetre);
void affichage_touche_appuyer(int touche);

// Définition du sprite du vaisseau (11x8)
t_sprite vaisseau = {
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
typedef enum
{
    TOUCHE_AUCUNE = 0, // aucune touche pressée
    TOUCHE_GAUCHE = 1, // flèche gauche
    TOUCHE_DROITE = 2, // flèche droite
    TOUCHE_ESPACE = 3, // espace
    TOUCHE_ESC = -1    // ESC
} Touche;

#define NB_COL 5
#define NB_LIG 3
#define ESPACE_X 40   // espacement horizontal entre aliens
#define ESPACE_Y 40   // espacement vertical entre rangées




int main()
{
    int L = 400; // largeur fenêtre
    int H = 600; // hauteur fenêtre

    // Initialisation de la fenêtre graphique
    if (initAffichage(L, H) != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de la fenêtre\n");
        return -1;
    }
    t_alien aliens[NB_LIG * NB_COL];

    int touche = 0;

    int largeur_sprite = 4 * SPRITE_X;
    int hauteur_sprite = 4 * SPRITE_Y;

    int x = (L - largeur_sprite) / 2; // centrage horizontal
    int y = H - hauteur_sprite - 10;  // position basse avec marge

    // Boucle principale
    while (touche != -1)
    {
        deplacement_sprite(touche, &x, &y, &largeur_sprite, &L);
        // Affichage du vaisseau
        afficheSprite(vaisseau, x, y, ROUGE);

        // Mise à jour de l'affichage et lecture des touches
        touche = miseAJourAffichage(50); // temporisation en µs
        affichage_touche_appuyer(touche);
    }
    return 0;
}

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
}
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