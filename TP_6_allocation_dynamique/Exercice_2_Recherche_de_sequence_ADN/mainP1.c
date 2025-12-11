#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"
#include "individu.h"

#define MAX_INDIVIDUS 10
int main()
{

    t_indiv individu;
    bool verif_open_file = lecture_adn("ADN.txt", &individu);
    printf("Lecture du fichier ADN.txt : %s\n\n", verif_open_file ? "Réussie" : "Échouée");
    printf(fflush(stdout));

    printf("Nom: %s\n\n", individu.nom);
    printf(fflush(stdout));

    printf("Séquence ADN: %s\n", individu.sequence_ADN);
    printf(fflush(stdout));

    detruire_indiv(&individu);
    return 0;
}
