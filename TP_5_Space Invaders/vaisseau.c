#include "vaisseau.h"

// Définition du sprite du vaisseau
t_vaisseau vaisseau = {
    .x = 0,
    .y = 0,
    .sprite = {
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}},
    .missile_x = 0,
    .missile_y = 0,
    .missileActif = false};

t_sprite missile_sprite = {
    {1}, // 1 pixel de large
};

void deplaceVaisseau(t_vaisseau *v, int touche, int largeur_fenetre)
{
    // Déplacement horizontal
    if (touche == TOUCHE_GAUCHE)
        v->x -= 5;
    else if (touche == TOUCHE_DROITE)
        v->x += 5;

    // Limites de la fenêtre
    if (v->x < 0)
        v->x = 0;
    if (v->x > largeur_fenetre - SPRITE_X)
        v->x = largeur_fenetre - SPRITE_X;

    // Tir
    if (touche == TOUCHE_ESPACE && !v->missileActif)
    {
        v->missileActif = true;
        v->missile_x = v->x + SPRITE_X / 2; // centre du vaisseau
        v->missile_y = v->y - 1;            // juste au-dessus du vaisseau
    }

    // Déplacement du missile
    if (v->missileActif)
    {
        v->missile_y -= 10;   // vitesse du missile
        if (v->missile_y < 0) // sort de l'écran
            v->missileActif = false;
    }

    // Affichage
    afficheSprite(v->sprite, v->x, v->y, ROUGE);
    if (v->missileActif)
    {
        afficheMissile(v);
    }
}

// Fonction pour afficher le missile
void afficheMissile(t_vaisseau *v)
{
    if (v->missileActif)
    {
        // Affiche le missile comme un petit sprite
        afficheSprite(missile_sprite, v->missile_x, v->missile_y, BLANC);
    }
}

int testMissile(t_vaisseau *v, t_alien *aliens, int nbAliens)
{
    if (!v->missileActif)
    {
        return -1; // pas de missile en vol
    }
    // Parcours les n aliens présent dans le jeux
    for (int i = 0; i < nbAliens; i++)
    {
        t_alien *a = &aliens[i];

        // Vérifie si l'alien est encore actif
        if (!a->sprite_actif)
            continue;

        // Vérifie collision simple rectangle (rectangle de taille de l'alien)
        if (v->missile_x >= a->x && v->missile_x < a->x + SPRITE_X * 4 &&
            v->missile_y >= a->y && v->missile_y < a->y + SPRITE_Y * 4)
        {

            v->missileActif = false; // le missile disparait
            return i;                // renvoie l'indice de l'alien touché
        }
    }

    return -1; // aucun alien touché
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
