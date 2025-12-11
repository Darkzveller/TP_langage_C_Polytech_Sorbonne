#ifndef INDIVIDU_H
#define INDIVIDU_H

typedef struct  {
    char nom[50+1+50];      // Nom de l'individu (50 caractères max + 1 pour le '\0')
    char sequence_ADN[1000+1];// Séquence ADN (1000 caractères max + 1 pour le '\0')
}t_indiv;

int lecture_adn(const char *nom_fichier, t_indiv *ind);
#endif
