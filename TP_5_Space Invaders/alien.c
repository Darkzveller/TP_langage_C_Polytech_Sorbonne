#include "alien.h"
#include "affichage.h"
// Sprites des aliens
t_sprite alien_sprite1 = {
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0}};

t_sprite alien_sprite2 = {
    {0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}};

void deplaceAlien(t_alien *a)
{
    // Déplacement
    a->compteur = (a->compteur + 1) % 50;
    if (a->compteur < 25)
        a->x += 2;
    else
        a->x -= 2;
    if (a->compteur == 49)
        a->y += 5;

    // Animation (ralentir avec un facteur)
    a->compteur_anim = (a->compteur_anim + 1) % 10; // changer sprite tous les 10 cycles
    if (a->compteur_anim == 0) {
        a->sprite_actif = (a->sprite_actif + 1) % 2;
    }
}

void initAlien(t_alien *aliens, int nb_ligne, int nb_colonne, int espace_x, int espace_y)
{
    for (int i = 0; i < nb_ligne; i++)
    {
        for (int j = 0; j < nb_colonne; j++)
        {
            int index = i * nb_colonne + j;
            aliens[index].x = 50 + j * espace_x;
            aliens[index].y = 50 + i * espace_y;
            aliens[index].compteur = 0;
            aliens[index].sprite_actif = 0;

            // Couleur + sprites
            aliens[index].sprite1 = &alien_sprite1;
            aliens[index].sprite2 = &alien_sprite2;

            if (i == 0) aliens[index].couleur = ROUGE;
            else if (i == 1) aliens[index].couleur = VERT;
            else aliens[index].couleur = BLEU;
        }
    }
}

void afficheAlien(t_alien *a)
{
    t_sprite *sprite_to_draw = (a->sprite_actif == 0) ? a->sprite1 : a->sprite2;
    afficheSprite(*sprite_to_draw, a->x, a->y, a->couleur);
}
