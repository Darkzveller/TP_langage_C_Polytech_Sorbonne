#include "individu.h"

int lecture_adn(const char *nom_fichier, t_indiv *ind)
{
    char prenom[TAILLE_NOM * 2 + 1];
    ind->nom = (char *)malloc(TAILLE_NOM);
    ind->sequence_ADN = (char *)malloc(TAILLE_SEQUENCE_ADN);

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

void detruire_indiv(t_indiv *ind)
{
    printf("\n\n\n\nTraitement de la destruction de t_indiv\n");
    printf(fflush(stdout));
    if (ind->nom != NULL)
    {
        printf("Libération du noms \n");
        printf(fflush(stdout));

        free(ind->nom);
        ind->nom = NULL;
    }
    else
    {
        printf("Nom déjà NULL\n");
        printf(fflush(stdout));
    }

    if (ind->sequence_ADN != NULL)
    {
        printf("Libération de la séquence ADN \n");
        printf(fflush(stdout));

        free(ind->sequence_ADN);
        ind->sequence_ADN = NULL;
    }
    else
    {
        printf("Séquence ADN déjà NULL\n");
        printf(fflush(stdout));
    }

    printf("t_indiv détruit avec succès.\n");
    printf(fflush(stdout));
}
