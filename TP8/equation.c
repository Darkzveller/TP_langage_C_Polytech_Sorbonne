#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "arbre.h"
#include "lectureInfixee.h"

// Fonction récursive pour afficher un arbre en notation post-fixée
void afficherArbrePostFixe(t_noeud *arbre)
{
    if (!arbre)
    {
        return;
    }

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

void afficherArbreInfixe(t_noeud *arbre)
{
    if (!arbre)
        return;

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
        printf("%s(", arbre->chaine); // nom de la fonction
        afficherArbreInfixe(arbre->fil_gauche);
        printf(")");
    }
    else if (nFils == 2)
    {
        // opérateur binaire
        printf("(");
        afficherArbreInfixe(arbre->fil_gauche);
        printf(" %s ", arbre->chaine); // opérateur
        afficherArbreInfixe(arbre->fil_droit);
        printf(")");
    }
}

// Evaluation simple : ne gère que les feuilles
int evaluer(t_noeud *arbre)
{
    if (!arbre)
    {
        return 0;
    }

    int nFils = nbFils(arbre);

    if (nFils == 0)
    {
        // feuille : soit nombre réel
        if (arbre->chaine == NULL)
        {
            // c'est un nombre réel
            return 1;
        }
        else
        {
            // c'est une variable
            return 0;
        }
    }

    return 0;
}

// Fonction pour remplacer un nœud par une feuille contenant la valeur val
void remplacerNoeud(t_noeud *arbre, float val)
{
    if (!arbre)
        return;

    // Libére récursivement fils gauche et droit
    if (arbre->fil_gauche != NULL)
    {
        remplacerNoeud(arbre->fil_gauche, 0);
        arbre->fil_gauche = NULL;
    }
    if (arbre->fil_droit != NULL)
    {
        remplacerNoeud(arbre->fil_droit, 0);
        arbre->fil_droit = NULL;
    }

    // Libère la chaine existante
    if (arbre->chaine != NULL)
    {
        free(arbre->chaine);
        arbre->chaine = NULL;
    }

    // On met a jour
    arbre->valeur = val;
    arbre->fil_gauche = NULL;
    arbre->fil_droit = NULL;
    arbre->chaine = NULL;
}

int evaluer_v2(t_noeud *arbre)
{

    if (!arbre)
    {
        return 0;
    }

    int nFils = nbFils(arbre);

    if (nFils == 0)
    {
        // feuille : soit nombre réel
        if (arbre->chaine == NULL)
        {
            // c'est un nombre réel
            return 1;
        }
        else
        {
            // c'est une variable
            return 0;
        }
    }
    // Fonction unaire
    if (nFils == 1)
    {
        if (!evaluer(arbre->fil_gauche)){
            return 0;}

        // Vérifier que c'est une fonction connue
        if (arbre->chaine != NULL && strcmp(arbre->chaine, "sin") == 0)
        {
            float resultat = sin(arbre->fil_gauche->valeur);
            // Remplacer le nœud par la valeur
            remplacerNoeud(arbre, resultat);
            return 1;
        }
        else
        {
            // Fonction non supportée
            return 0;
        }
    }

    return 0;
}
