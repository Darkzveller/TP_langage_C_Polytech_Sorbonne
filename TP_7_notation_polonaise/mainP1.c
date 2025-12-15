#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "malloc.h"
#include "pile.h"
/*
""""""""""""""""""""""""""""""""Méthode lancement du code"""""""""""""""""""""""""""""""""""""""""""
Pour exécuter le code, il faut effectuer : 
    - Nettoye le terminal dans un premier
    - Supprime tous les .o et .out
    - Compile et lance  le code mainP1.c spécifquement

clear && make mproper && make MAIN=mainP1.c run
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
*/

int main()
{
    printf("Vous avez lancé %s\n", __FILE__);  // __FILE__ contient le nom du fichier source

    t_element *pile = NULL; // pile vide au départ

    /* Empilement de quelques valeurs */
    for (float i = 0; i <6; i++)
    {
        pile = empiler(pile, i);
    }
    /* Affichage de la pile */
    afficher(pile);

    /* Vidage de la pile avant de quitter */
    pile = vider(pile);

    return 0;
}
