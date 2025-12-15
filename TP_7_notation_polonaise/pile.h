#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"
#include "math.h"
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
t_element* addition(t_element* sommet);
t_element* action(t_element* sommet, char* saisie);

t_element *soustraction(t_element *sommet);
t_element *multiplication(t_element *sommet);
t_element *division(t_element *sommet);
t_element *sinus(t_element *sommet);
t_element *dupliquer(t_element *sommet);

#endif
