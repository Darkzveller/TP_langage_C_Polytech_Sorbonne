#include "individu.h"
#include "score.h"
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
// Version 1 qui fonctionne très bien a condition qu'on alloue l'entiereté
// void lecture_adn(FILE *file, t_indiv *ind)
// {
//     char prenom[TAILLE_NOM * 2]; // Pour stocker le prénom temporairement
//     ind->nom = (char *)malloc(TAILLE_NOM);// Allocation dynamique pour le nom
//     ind->sequence_ADN = (char *)malloc(TAILLE_SEQUENCE_ADN);// Allocation dynamique pour la séquence ADN

//     /* On récupére les deux pairs de coordonnées de départ et arrivée */
//     fscanf(file, "%s %s %s", ind->nom, prenom, ind->sequence_ADN);
//     strcat(ind->nom, " ");
//     strcat(ind->nom, prenom);
// }

// Version 2 qui fonctionne très bien en allouant juste la taille nécessaire
void lecture_adn(FILE *file, t_indiv *ind)
{
    char nom_tmp[TAILLE_NOM];           // Buffer temporaire pour le prénom
    char prenom_tmp[TAILLE_NOM];        // Buffer temporaire pour le prénom
    char adn_temp[TAILLE_SEQUENCE_ADN]; // Buffer temporaire pour le nom

    fscanf(file, "%50s %50s %10000s", nom_tmp, prenom_tmp, adn_temp);
    // Allouer la mémoire nécessaire pour le nom complet
    ind->nom = (char *)malloc(strlen(nom_tmp) + strlen(prenom_tmp) + 2); // +2 pour l'espace et le caractère nul
    if (ind->nom == NULL)
    {
        printf("Erreur d'allocation mémoire pour le nom\n");
        exit(EXIT_FAILURE); // Gérer l'erreur d'allocation mémoire
    }
    // Construire le nom complet
    strcpy(ind->nom, nom_tmp);
    strcat(ind->nom, " ");
    strcat(ind->nom, prenom_tmp);

    ind->sequence_ADN = (char *)malloc(strlen(adn_temp) + 1); // Allocation dynamique pour la séquence ADN + le caractère nul
    if (ind->sequence_ADN == NULL)
    {
        printf("Erreur d'allocation mémoire pour le nom\n");
        exit(EXIT_FAILURE); // Gérer l'erreur d'allocation mémoire
    }
    // Construire le nom complet
    strcpy(ind->sequence_ADN, adn_temp);
}

void detruire_indiv(t_indiv *ind)
{
    // printf("\nTraitement de la destruction de t_indiv\n");
    // fflush(stdout);
    if (ind->nom != NULL)
    {
        // printf("Libération du noms : %s\n", ind->nom);
        // fflush(stdout);

        free(ind->nom);
        ind->nom = NULL;
    }
    // else
    // {
    //     printf("Nom déjà NULL\n");
    //     fflush(stdout);
    // }

    if (ind->sequence_ADN != NULL)
    {
        // printf("Libération de la séquence ADN \n");
        // fflush(stdout);

        free(ind->sequence_ADN);
        ind->sequence_ADN = NULL;
    }
    // else
    // {
    //     printf("Séquence ADN déjà NULL\n");
    //     fflush(stdout);
    // }

    // printf("t_indiv détruit avec succès.\n");
    // fflush(stdout);
}

void calculeSimilarite(t_indiv *ind, char *sequence_fragment)
{
    // Calcul du score d'alignement global
    int score = algorithme_needlman_wunsch(ind->sequence_ADN, sequence_fragment);

    // On récupère la longueur de la séquence la plus courte
    // int len_plus_courte;
    // if (strlen(ind->sequence_ADN) < len_plus_courte)
    // {
    //     len_plus_courte = strlen(ind->sequence_ADN);
    // }
    // else
    // {
    //     len_plus_courte = strlen(sequence_fragment);
    // }

    int len_seq1 = strlen(ind->sequence_ADN);
    int len_seq2 = strlen(sequence_fragment);

    int len_plus_courte;
    if (len_seq1 < len_seq2)
    {
        len_plus_courte = len_seq1;
    }
    else
    {
        len_plus_courte = len_seq2;
    }

    // Calcul du pourcentage d'inclusion
    float pourcentage = pourcentage_inclusion(score, len_plus_courte);

    // Stocker dans l'individu
    ind->similarite = pourcentage;
}
