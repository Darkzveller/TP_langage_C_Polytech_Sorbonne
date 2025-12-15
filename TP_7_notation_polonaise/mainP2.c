#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"
#include <math.h>
#include "pile.h"

int main()
{
    printf("Vous avez lancé %s\n", __FILE__);
    fflush(stdout);

    t_element *pile = NULL; // pile vide au départ
    char buffer[1000];      // buffer pour la saisie
    int quitter = 0;

    printf("Entrez un nombre ou une opération (+, -, *, /, SIN) (EXIT pour quitter) :\n");

    while (!quitter)
    {

        if (scanf("%999s", buffer) != 1)
        {
            printf("Erreur de lecture.\n");
            continue;
        }

        // Vérifier si l'utilisateur veut quitter
        if (strcmp(buffer, "EXIT") == 0)
        {
            quitter = 1;
            break;
        }

        // Conversion en double
        char *fin_conversion;
        double valeur = strtod(buffer, &fin_conversion);

        if (*fin_conversion == '\0')
        {
            // C'est un nombre, on empile
            pile = empiler(pile, valeur);
            printf("Vous avez saisi : %f\n", valeur);
        }
        else
        {
            // Ce n'est pas un nombre -> c'est une opération
            pile = action(pile, buffer);
        }
    }

    // Afficher la pile complète une seule fois avant de quitter
    printf("\nPile actuelle :\n");
    afficher(pile);

    // Vider la pile avant de quitter
    pile = vider(pile);

    printf("\nProgramme terminé.\n");
    return 0;
}
// 12 35 + 86 0.9 + 35 / 56 87 25 + / + *
