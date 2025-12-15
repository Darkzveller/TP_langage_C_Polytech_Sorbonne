
#include "pile.h"

t_element *empiler(t_element *sommet, double reel)
{
    /*
    Allocation de la mémoire attribué a la structure nouveau
    */
    t_element *nouveau = (t_element *)malloc(sizeof(t_element));

    // échec allocation : on ne modifie pas la pile
    if (nouveau == NULL)
    {
        return sommet;
    }

    nouveau->valeur = reel;
    nouveau->suivant = sommet; // l'ancien sommet devient le suivant

    /*
    Le nouvel élément devient le sommet de la pile, lafonction retourne donc le nouveau pointeur de pile
    */
    return nouveau;
}

t_element *depiler(t_element *sommet)
{
    t_element *nouveau_sommet;

    // Cas pile vide
    if (sommet == NULL)
    {
        return NULL;
    }

    nouveau_sommet = sommet->suivant; // futur sommet
    free(sommet);                     // libération de l'ancien sommet

/*
L’élément situé au sommet de la pile est supprimé.
L’élément suivant devient le nouveau sommet de la pile,
et son pointeur est retourné.
*/
    return nouveau_sommet;
}

t_element *vider(t_element *sommet)
{
    while (sommet != 0)
    {
        sommet = depiler(sommet);
    }
    return NULL;
}

void afficher(t_element *sommet)
{
    printf("haut de la pile\n");

    while (sommet != NULL)
    {
        printf("%f\n", (float)sommet->valeur);
        sommet = sommet->suivant;
    }

    printf("bas de la pile\n");
}
