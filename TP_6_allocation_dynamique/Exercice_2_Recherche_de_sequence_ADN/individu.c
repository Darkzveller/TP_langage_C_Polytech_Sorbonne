#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "individu.h"

int lecture_adn(const char *nom_fichier, t_indiv *ind)
{
    char prenom[50 + 1];

    FILE *file = fopen(nom_fichier, "r");
    if (file == NULL)
    {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return EXIT_FAILURE; // Renvoie un code erreur, comme quoi on a pas réussi a ouvrir le fichier
    }

    /* On récupére les deux pairs de coordonnées de départ et arrivée */
    fscanf(file, "%s %s %s", ind->nom, prenom, ind->sequence_ADN);
    strcat(ind->nom, " ");
    strcat(ind->nom, prenom);

    fclose(file);
    return 1;
}