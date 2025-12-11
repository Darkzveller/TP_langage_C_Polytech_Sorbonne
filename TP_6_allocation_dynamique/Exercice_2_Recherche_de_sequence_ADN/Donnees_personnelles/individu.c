#include "individu.h"

int ouverture_fichier(const char *nom_fichier, FILE **file)
{
    *file = fopen(nom_fichier, "r");
    if (*file == NULL)
    {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return EXIT_FAILURE; // Renvoie un code erreur, comme quoi on a pas réussi a ouvrir le fichier
    }
    return 1;
}
void lecture_adn(FILE *file, t_indiv *ind)
{
    char prenom[TAILLE_NOM * 2]; // Pour stocker le prénom temporairement
    ind->nom = (char *)malloc(TAILLE_NOM);// Allocation dynamique pour le nom
    ind->sequence_ADN = (char *)malloc(TAILLE_SEQUENCE_ADN);// Allocation dynamique pour la séquence ADN

    /* On récupére les deux pairs de coordonnées de départ et arrivée */
    fscanf(file, "%s %s %s", ind->nom, prenom, ind->sequence_ADN);
    strcat(ind->nom, " ");
    strcat(ind->nom, prenom);
}

void detruire_indiv(t_indiv *ind)
{
    printf("\nTraitement de la destruction de t_indiv\n");
    printf(fflush(stdout));
    if (ind->nom != NULL)
    {
        printf("Libération du noms : %s\n", ind->nom);
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
