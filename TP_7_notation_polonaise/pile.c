
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

// Additionne les deux premiers éléments de la pile
t_element *addition(t_element *sommet)
{
    // Vérifier s'il y a au moins deux éléments
    if (sommet == NULL || sommet->suivant == NULL)
    {
        printf("Addition impossible : pas assez d'opérandes.\n");
        return sommet; // retourne la pile inchangée
    }

    // Dépiler les deux premiers éléments
    double a = sommet->valeur;
    t_element *temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    double b = sommet->valeur;
    temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    // Calculer le résultat
    double resultat = a + b;

    // Empiler le résultat
    sommet = empiler(sommet, resultat);

    return sommet;
}

t_element *action(t_element *sommet, char *saisie)
{

    // Vérifier si la saisie correspond à l'addition
    if (strcmp(saisie, "ADD") == 0 || strcmp(saisie, "+") == 0)
    {
        sommet = addition(sommet);
    }
    else
    {
        printf("Action '%s' non reconnue.\n", saisie);
    }

    return sommet;
}

// Dépiler deux éléments, effectuer l'opération, puis empiler le résultat
t_element *soustraction(t_element *sommet)
{
    if (sommet == NULL || sommet->suivant == NULL)
    {
        printf("Soustraction impossible : pas assez d'opérandes.\n");
        return sommet;
    }

    double a = sommet->valeur;
    t_element *temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    double b = sommet->valeur;
    temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    double resultat = b - a; // b - a pour respecter l'ordre de la pile
    sommet = empiler(sommet, resultat);
    return sommet;
}

t_element *multiplication(t_element *sommet)
{
    if (sommet == NULL || sommet->suivant == NULL)
    {
        printf("Multiplication impossible : pas assez d'opérandes.\n");
        return sommet;
    }

    double a = sommet->valeur;
    t_element *temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    double b = sommet->valeur;
    temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    double resultat = a * b;
    sommet = empiler(sommet, resultat);
    return sommet;
}

t_element *division(t_element *sommet)
{
    if (sommet == NULL || sommet->suivant == NULL)
    {
        printf("Division impossible : pas assez d'opérandes.\n");
        return sommet;
    }

    double a = sommet->valeur;
    t_element *temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    double b = sommet->valeur;
    temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    if (a == 0)
    {
        printf("Division par zéro impossible.\n");
        // Remettre les opérandes dans l'ordre initial
        sommet = empiler(sommet, b);
        sommet = empiler(sommet, a);
        return sommet;
    }

    double resultat = b / a; // b / a pour respecter l'ordre de la pile
    sommet = empiler(sommet, resultat);
    return sommet;
}

t_element *sinus(t_element *sommet)
{
    if (sommet == NULL)
    {
        printf("Sinus impossible : la pile est vide.\n");
        return sommet;
    }

    double a = sommet->valeur;
    t_element *temp = sommet;
    sommet = sommet->suivant;
    free(temp);

    double resultat = sin(a); // sinus en radians
    sommet = empiler(sommet, resultat);
    return sommet;
}

t_element *dupliquer(t_element *sommet)
{
    if (sommet == NULL)
    {
        // La pile est vide, rien à dupliquer
        return sommet;
    }

    // Empiler une nouvelle valeur identique au sommet actuel
    return empiler(sommet, sommet->valeur);
}
