#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"
#include "pile.h"

int main() {
    printf("Vous avez lancé %s\n", __FILE__);
    fflush(stdout);

    t_element *pile = NULL;    // pile vide au départ
    char buffer[1000];         // buffer pour la saisie
    int quitter = 0;
        printf("Entrez un nombre (ou EXIT pour quitter) : ");
        fflush(stdout);

    while (!quitter) {

        if (scanf("%999s", buffer) != 1) {
            printf("Erreur de lecture.\n");
            continue;
        }

        // Vérifier si l'utilisateur veut quitter
        if (strcmp(buffer, "EXIT") == 0) {
            quitter = 1;
            break;
        }

        // Conversion en double
        char *fin_conversion;
        double valeur = strtod(buffer, &fin_conversion);

        // Vérifier si la conversion a réussi
        if (*fin_conversion != '\0') {
            printf("'%s' n'est pas un nombre valide.\n", buffer);
            continue;
        }

        // Empiler la valeur
        pile = empiler(pile, valeur);

        // Afficher seulement la valeur saisie
        printf("Vous avez saisi : %f\n", valeur);
    }

    // Afficher la pile complète une seule fois avant de quitter
    printf("Pile actuelle :\n");
    afficher(pile);

    // Vider la pile avant de quitter
    pile = vider(pile);

    printf("Programme terminé.\n");
    return 0;
}
