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
    if (!a->vivant)
        return; // ne pas déplacer un alien mort

    // Déplacement horizontal / vertical
    a->compteur = (a->compteur + 1) % 50;
    if (a->compteur < 25)
    {
        a->x += 2;
    }
    else
    {
        a->x -= 2;
    }
    if (a->compteur == 49)
    {
        a->y += 5;
    }

    // Animation
    a->compteur_anim = (a->compteur_anim + 1) % 15;
    if (a->compteur_anim == 0)
    {
        a->sprite_actif = 1 - a->sprite_actif; // alterne 0 et 1
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
            aliens[index].vivant = true;
            aliens[index].eclair = 0;
            // Couleur + sprites
            aliens[index].sprite1 = &alien_sprite1;
            aliens[index].sprite2 = &alien_sprite2;

            if (i == 0)
            {
                aliens[index].couleur = ROUGE;
            }
            else if (i == 1)
            {
                aliens[index].couleur = VERT;
            }
            else
            {
                aliens[index].couleur = BLEU;
            }
        }
    }
}

void afficheAlien(t_alien *a)
{
    // Si l'alien est mort et que l'éclair est terminé, on ne l'affiche pas
    if (!a->vivant && a->eclair == 0)
        return;

    // Si l'alien est mort mais l'éclair doit encore être affiché
    if (!a->vivant && a->eclair > 0)
    {
        // Crée un sprite blanc temporaire
        t_sprite blanc;
        for (int i = 0; i < SPRITE_Y; i++)
        {
            for (int j = 0; j < SPRITE_X; j++)
            {
                blanc[i][j] = 1; // pixel actif
            }
        }
        // Affiche le sprite blanc à la position de l'alien
        afficheSprite(blanc, a->x, a->y, BLANC);

        // Décrémente le compteur d'éclair
        a->eclair--;
        return;
    }

    // Sinon, alien vivant → affiche le sprite actif
    t_sprite *sprite_to_draw = (a->sprite_actif == 0) ? a->sprite1 : a->sprite2;
    afficheSprite(*sprite_to_draw, a->x, a->y, a->couleur);
}
