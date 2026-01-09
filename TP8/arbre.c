

#include <stdlib.h>
#include <string.h>
#include "arbre.h"
// Fonction qui crée un nœud de l'arbre
t_noeud *creerNoeud(float val, char *ch, t_noeud *filsG, t_noeud *filsD)
{
    // Allocation de la mémoire pour le nœud
    t_noeud *create_noeud = malloc(sizeof(t_noeud));
    if (create_noeud == NULL)
    {
        return NULL;
    }
    // Initialisation des champs du nœud
    create_noeud->valeur = val;
    create_noeud->fil_gauche = filsG;
    create_noeud->fil_droit = filsD;
    // Dans le cas ou une chaîne est fournie
    if (ch != NULL)
    {
        // Allocation mémoire pour la chaîne
        create_noeud->chaine = malloc(strlen(ch) + 1);
        if (create_noeud->chaine == NULL)
        {
            free(create_noeud);
            return NULL;
        }
                // Copie de la chaîne dans le nœud
        strcpy(create_noeud->chaine, ch);
    }else
{
    create_noeud->chaine = NULL;
}


    return create_noeud;
}

t_noeud *creerNoeudOp(t_noeud *filsG, char *ch, t_noeud *filsD)
{
    return creerNoeud(0, ch, filsG, filsD);
}
t_noeud *creerFeuilleReel(float val)
{
    return creerNoeud(val, NULL, NULL, NULL);
}
t_noeud *creerFeuilleVar(char *ch)
{
    return creerNoeud(0, ch, NULL, NULL);
}

void detruireArbre(t_noeud *arbre)
{
    if (arbre == NULL)
    {

        return;
    }

    // Le noeud parents possédent des enfant on les supprime d'abord
    detruireArbre(arbre->fil_gauche);
    detruireArbre(arbre->fil_droit);

    // On libère l'allocation fait part creer noeud
    if (arbre->chaine != NULL)
    {
        free(arbre->chaine);
    }

    free(arbre);
}

int nbFils(t_noeud *noeud)
{
    int nb = 0;

    if (noeud == NULL)
    {
        return 0;
    }

    if (noeud->fil_gauche != NULL)
    {
        nb++;
    }

    if (noeud->fil_droit != NULL)
    {
        nb++;
    }

    return nb;
}
