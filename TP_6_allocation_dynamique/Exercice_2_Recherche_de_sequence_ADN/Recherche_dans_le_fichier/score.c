#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max3(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int algorithme_needlman_wunsch(char *seq_adn_1, char *seq_adn_2)
{
    int cout;
    // Implémentation de l'algorithme de Needleman-Wunsch
    // Cette fonction calcule et retourne le score d'alignement global entre seq1 et seq2
    // Pour l'instant, cette fonction est un stub et retourne 0

    int len_seq_adn_1 = strlen(seq_adn_1) + 1;
    int len_seq_adn_2 = strlen(seq_adn_2) + 1;

    // Création de la matrice de score
    int score_matrice[len_seq_adn_1 * len_seq_adn_2];
    // Initialisation de la matrice
    for (int i = 0; i < len_seq_adn_1; i++)
    {
        score_matrice[i * len_seq_adn_2] = 0; // Initialisation de la première colonne
    }
    for (int j = 0; j < len_seq_adn_2; j++)
    {
        score_matrice[j] = 0; // Initialisation de la première colonne
    }

    for (int i = 1; i < len_seq_adn_1; i++)
    {
        for (int j = 1; j < len_seq_adn_2; j++)
        {
            if (seq_adn_1[i - 1] == seq_adn_2[j - 1])
            {
                cout = 1;
            }
            else
            {
                cout = -1;
            }
            score_matrice[i * len_seq_adn_2 + j] = max3(
                score_matrice[(i - 1) * len_seq_adn_2 + j] - 1,
                score_matrice[i * len_seq_adn_2 + (j - 1)] - 1,
                score_matrice[(i - 1) * len_seq_adn_2 + (j - 1)] + cout);
        }
    }
    // Recherche du score maximal
    int max_score = score_matrice[0];
    for (int i = 0; i < len_seq_adn_1 * len_seq_adn_2; i++)
    {
        if (score_matrice[i] > max_score)
        {
            max_score = score_matrice[i];
        }
    }

    return max_score;
}

float pourcentage_inclusion(float score_obtenu, float longueur_sequence_plus_courte)
{
    if (longueur_sequence_plus_courte == 0)
    {
        return 0; // Éviter la division par zéro
    }
    return (score_obtenu * 100.0) / longueur_sequence_plus_courte;
}