#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "affichage.h"
#include "alien.h"

/*

make mproper && make clean && make run



*/
// Permet de calculer le déplacement du sprite de l'utilisateur, tout en gardant le code plus lisible
void deplacement_sprite(int touche, int *x, int *y, int *largeur_sprite, int *largeur_fenetre);
// Permet d'afficher la touche sur laquelle on appuie, tout en gardant le code plus lisible
void affichage_touche_appuyer(int touche);
// Définition des touches pour la fonction affichage_touche_appuyer
typedef enum
{
    TOUCHE_AUCUNE = 0, // aucune touche pressée
    TOUCHE_GAUCHE = 1, // flèche gauche
    TOUCHE_DROITE = 2, // flèche droite
    TOUCHE_ESPACE = 3, // espace
    TOUCHE_ESC = -1    // ESC
} Touche;

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

t_sprite alien_sprite = {
    {0,0,1,1,1,1,1,1,1,0,0},  // Haut du visage (cheveux)
    {0,1,0,0,1,1,1,0,0,1,0},  // Yeux
    {1,0,1,0,1,1,1,0,1,0,1},  // Lunettes
    {1,0,1,1,1,1,1,1,1,0,1},  // Nez et bouche
    {1,0,1,1,1,1,1,1,1,0,1},  // Bouche
    {1,0,0,0,1,1,1,0,0,0,1},  // Menton
    {0,1,0,0,0,0,0,0,0,1,0},  // Joues
    {0,0,1,1,1,1,1,1,1,0,0}   // Bas du visage
};

#define NB_COLONNE 5
#define NB_LIGNE 3
#define ESPACEMENT_X_ALIEN 60 // espacement horizontal entre aliens
#define ESPACEMENT_Y_ALIEN 60 // espacement vertical entre rangées

int L = 400; // largeur fenêtre
int H = 600; // hauteur fenêtre

int touche = 0; // Lecture de la touche appuyer

int largeur_sprite = 4 * SPRITE_X; // Calcul la taille de notre sprite
int hauteur_sprite = 4 * SPRITE_Y; // Calcul la taille de notre sprite

int main()
{

    // Initialisation de la fenêtre graphique
    if (initAffichage(L, H) != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de la fenêtre\n");
        return -1;
    }
    t_alien aliens[NB_LIGNE * NB_COLONNE]; // Toutes les variables déclarer dans la strcuture seront des tableau de taille NB_LIGNENE et NB_COLONNEONNE

    int x = (L - largeur_sprite) / 2; // centrage horizontal
    int y = H - hauteur_sprite - 10;  // position basse avec marge
    initAlien(aliens, NB_LIGNE, NB_COLONNE, ESPACEMENT_X_ALIEN, ESPACEMENT_Y_ALIEN);
    // Boucle principale
    while (touche != TOUCHE_ESC)
    {

        for (int i = 0; i < NB_LIGNE * NB_COLONNE; i++)
        {
            deplaceAlien(&aliens[i]); // déplacement
            afficheSprite(alien_sprite, aliens[i].x, aliens[i].y, aliens[i].couleur);
        }
        // Déplace notre sprite
        deplacement_sprite(touche, &x, &y, &largeur_sprite, &L);
        // Affichage du vaisseau
        afficheSprite(vaisseau, x, y, ROUGE);

        // Mise à jour de l'affichage et lecture des touches
        touche = miseAJourAffichage(50); // temporisation en µs
        affichage_touche_appuyer(touche);
    }
    return 0;
}

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