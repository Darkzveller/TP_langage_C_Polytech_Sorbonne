#ifndef __VAISSEAU_H__
#define __VAISSEAU_H__
#include "affichage.h"
#include "alien.h"
#include <stdio.h>
#include <stdbool.h>

typedef enum
{
    TOUCHE_AUCUNE = 0,
    TOUCHE_GAUCHE = 1,
    TOUCHE_DROITE = 2,
    TOUCHE_ESPACE = 3,
    TOUCHE_ESC = -1
} Touche;

typedef struct
{
    int x;           // position horizontale
    int y;           // position verticale
    t_sprite sprite; // sprite du vaisseau

    // Pour le missile
    int missile_x;
    int missile_y;
    bool missileActif; // true si un missile est en vol
} t_vaisseau;


// Déclaration du vaisseau global
extern t_vaisseau vaisseau;
extern t_sprite missile_sprite;

// Permet d'afficher la touche sur laquelle on appuie, tout en gardant le code plus lisible
void affichage_touche_appuyer(int touche);
// Fonction de déplacement
void deplaceVaisseau(t_vaisseau *v, int touche, int largeur_fenetre);

// Fonction pour afficher le missile
void afficheMissile(t_vaisseau *v);


int testMissile(t_vaisseau *v, t_alien *aliens, int nbAliens);

#endif