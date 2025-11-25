#ifndef __ALIEN_H__
#define __ALIEN_H__

// Structure représentant un alien
typedef struct {
    int x;      // position horizontale de notre alien
    int y;      // position verticale de notre alien
    int couleur;   // couleur de notre alien
    int compteur;
} t_alien;
// Fonction qui déplace un alien en fonction de son compteur
void deplaceAlien(t_alien *a);

void initAlien(t_alien *aliens, int nb_ligne, int nb_colonne, int espace_x, int espace_y);
#endif
