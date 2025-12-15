#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"

#ifndef PILE_H
#define PILE_H

typedef struct
{
    double valeur;           // valeur réelle stockée
    struct element *suivant; // pointeur vers l’élément suivant

} t_element;

t_element *empiler(t_element *sommet, double reel);
t_element *depiler(t_element *sommet);
t_element *vider(t_element *sommet);

void afficher(t_element* sommet);
#endif
