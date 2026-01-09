#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arbre.h"
#include "lectureInfixee.h"

// Fonction récursive pour afficher un arbre en notation post-fixée
void afficherArbrePostFixe(t_noeud *arbre)
{
    if (!arbre){
        return;}

    afficherArbrePostFixe(arbre->fil_gauche);
    afficherArbrePostFixe(arbre->fil_droit);

    if (arbre->chaine != NULL)
    {
        printf("%s ", arbre->chaine);
    }
    else
    {
        printf("%.2f ", arbre->valeur);
    }
}

void afficherArbreInfixe(t_noeud* arbre)
{
    if (!arbre) return;

    int nFils = nbFils(arbre);

    if (nFils == 0)
    {
        // feuille : nombre ou variable
        if (arbre->chaine != NULL)
            printf("%s", arbre->chaine);
        else
            printf("%.2f", arbre->valeur);
    }
    else if (nFils == 1)
    {
        // fonction unaire (ex: sin)
        printf("%s(", arbre->chaine);   // nom de la fonction
        afficherArbreInfixe(arbre->fil_gauche);
        printf(")");
    }
    else if (nFils == 2)
    {
        // opérateur binaire
        printf("(");
        afficherArbreInfixe(arbre->fil_gauche);
        printf(" %s ", arbre->chaine);   // opérateur
        afficherArbreInfixe(arbre->fil_droit);
        printf(")");
    }
}

