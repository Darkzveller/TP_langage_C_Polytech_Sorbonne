#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"

#ifndef INDIVIDU_H
#define INDIVIDU_H

#define TAILLE_NOM 50
#define TAILLE_SEQUENCE_ADN 10000

typedef struct  {
    char* nom;      // Nom de l'individu 
    char* sequence_ADN;// Séquence ADN 
}t_indiv;


int ouverture_fichier(const char *nom_fichier, FILE **file);
/*  
Lit les données ADN d'un individu à partir d'un fichier
Paramètres :
    nom_fichier : nom du fichier à lire
    ind : pointeur vers la structure t_indiv où les données seront stockées

Retourne 1 en cas de succès, EXIT_FAILURE en cas d'erreur
*/
void lecture_adn(FILE *file, t_indiv *ind);
/*
    * Libère la mémoire allouée pour un individu
*/
void detruire_indiv(t_indiv *ind);
#endif
