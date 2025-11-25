#include "alien.h"
#include "affichage.h"

void deplaceAlien(t_alien *a)
{
    // compteur 0 → 49
    a->compteur = (a->compteur + 1) % 50;

    if (a->compteur < 25)
        a->x += 2;
    else
        a->x -= 2;

    // À la fin du cycle, on descend
    if (a->compteur == 49)
        a->y += 5;
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

            if (i == 0) aliens[index].couleur = ROUGE;
            else if (i == 1) aliens[index].couleur = VERT;
            else aliens[index].couleur = BLEU;
        }
    }
}
