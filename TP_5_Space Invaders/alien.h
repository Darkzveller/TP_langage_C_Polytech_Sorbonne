#ifndef __ALIEN_H__
#define __ALIEN_H__
#include "affichage.h"
#include <stdbool.h>

// Structure représentant un alien
typedef struct
{
    int x;       // position horizontale de notre alien
    int y;       // position verticale de notre alien
    int couleur; // couleur de notre alien
    int compteur;
    int compteur_anim;  // pour l'animation
    t_sprite *sprite1;  // sprite normal
    t_sprite *sprite2;  // sprite alternatif pour animation
    int sprite_actif;   // 0 ou 1
    bool vivant ; // true si l’alien est encore vivant
    int eclair;         

} t_alien;

// Fonction qui déplace un alien en fonction de son compteur
void deplaceAlien(t_alien *a);
// Initialise les aliens en une position
void initAlien(t_alien *aliens, int nb_ligne, int nb_colonne, int espace_x, int espace_y);
// FOnction qui permet d'afficher les aliens
void afficheAlien(t_alien *a);

#endif
