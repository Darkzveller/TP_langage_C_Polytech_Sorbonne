#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "score.h" // ton fichier score.c compilé en score.o

int main()
{
    // Chaînes préenregistrées
    char seq1[] = "abcdefgh";
    char seq2[] = "cdefg";
    // char seq1[] = "abcdefgh";
    // char seq2[] = "cdexfg";

    // Calcul du score avec Needleman-Wunsch
    int score = algorithme_needlman_wunsch(seq1, seq2);

    // Détermination de la longueur de la plus courte séquence
    int len_seq1 = strlen(seq1);
    int len_seq2 = strlen(seq2);
    int len_plus_courte;

    if (len_seq1 < len_seq2)
    {
        len_plus_courte = len_seq1; // len_seq1 est plus court
    }
    else
    {
        len_plus_courte = len_seq2; // len_seq2 est plus court ou égal
    }

    // Calcul du pourcentage d'inclusion
    float pourcentage = pourcentage_inclusion(score, len_plus_courte);

    // Affichage
    printf("Séquence 1 : %s\n", seq1);
    printf("Séquence 2 : %s\n", seq2);
    printf("Score d'alignement : %d\n", score);
    printf("Pourcentage d'inclusion : %.1f \n", pourcentage);

    return 0;
}
