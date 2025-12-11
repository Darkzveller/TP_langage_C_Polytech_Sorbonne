#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"
#include "individu.h"

#define MAX_INDIVIDUS 10
char *nom_fichier = "ADN.txt";
FILE *file;
int main()
{
    // Ouverture du fichier
    bool verif_open_file = ouverture_fichier(nom_fichier, &file);
    if (!verif_open_file)
    {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return 1;
    }

    // Tableau pour stocker les individus
    t_indiv individus[MAX_INDIVIDUS];
    int nb_lus = 0;

    // Lecture des individus
    for (int i = 0; i < MAX_INDIVIDUS; i++)
    {
        lecture_adn(file, &individus[i]);
        nb_lus++;
    }

    // Affichage des individus dans l'ordre inverse
    printf("\n--- Affichage dans l'ordre inverse ---\n");
    for (int i = nb_lus - 1; i >= 0; i--)
    {
        printf("Individu %d\n", i + 1);
        printf("Nom : %s\n", individus[i].nom);
        // printf("Séquencse ADN : %s\n\n", individus[i].sequence_ADN);
    }

    // Libération de la mémoire
    for (int i = 0; i < nb_lus; i++)
    {
        detruire_indiv(&individus[i]);
    }

    // Fermeture du fichier
    fclose(file);

    return 0;
}
