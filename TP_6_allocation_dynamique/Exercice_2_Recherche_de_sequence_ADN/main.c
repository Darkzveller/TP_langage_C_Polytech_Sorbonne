#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "individu.h"

int main()
{

    t_indiv individu;
    bool verif_open_file = lecture_adn("ADN.txt", &individu);
    printf("Lecture du fichier ADN.txt : %s\n\n", verif_open_file ? "Réussie" : "Échouée");
    printf("Nom: %s\n\n", individu.nom);
    printf("Séquence ADN: %s\n", individu.sequence_ADN);
    return 0;
}
