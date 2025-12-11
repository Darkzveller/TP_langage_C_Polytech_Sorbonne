#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"
#include "individu.h"
#include "score.h"

char fragment_suspect[] = "TAAAGGCCG-TAAGTTCCAAATT";
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

    // // Tableau pour stocker les individus
    t_indiv *individus = NULL;     // Tableau dynamique
    int capacite_individus = 0; // Capacité actuelle du tableau
    int nb_lus = 0;         // Nombre d'individus lus

    // Lecture des individus
    while (!feof(file))
    {
        // Si on atteint la capacité, on double le tableau
        if (nb_lus >= capacite_individus)
        {
            capacite_individus += 1;
            individus = realloc(individus, capacite_individus * sizeof(t_indiv));
            if (individus == NULL)
            {
                printf("Erreur d'allocation mémoire\n");
                fflush(stdout);
                exit(EXIT_FAILURE);
            }
        }

        // Lire un individu
        lecture_adn(file, &individus[nb_lus]);
        nb_lus++;
    }

    // t_indiv *individus = NULL;  // Tableau dynamique
    // int capacite_individus = 0; // Capacité actuelle du tableau
    // int nb_lus = 0;             // Nombre d'individus lus

    // Calcul et affichage des similarités
    printf("\n--- Similarités avec le fragment suspect ---\n");
    for (int i = 0; i < nb_lus; i++)
    {
        if (i == 0)
        {
            // printf("sequence adn  %s", individus[i].sequence_ADN);
        }
        calculeSimilarite(&individus[i], fragment_suspect);
        printf("Nom : %s, Similarité : %.1f\n", individus[i].nom, individus[i].similarite);
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
