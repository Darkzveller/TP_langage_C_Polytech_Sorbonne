#include <stdio.h>
#include "arbre.h"
#include "lectureInfixee.h"
#include "equation.h"

int main()
{
    printf("Vous avez lancer %s\n\n", __FILE__); // __FILE__ contient le nom du fichier source
    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");

    char saisie_caractere[200];
    t_noeud *arbre;
    printf("Saisir une expression: ");
    scanf("%s", &saisie_caractere);
    printf("\nVerification expression ecrite %s", saisie_caractere);

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
    arbre = creerArbreDepuisInfixee( saisie_caractere);

    printf("Affichage post-fixee : ");
    afficherArbrePostFixe(arbre);
    printf("\n");

    printf("Affichage infixeer : ");
    afficherArbreInfixe(arbre);
    printf("\n");

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
    detruireArbre(arbre);
    printf("Arbres detruits.\n");

    return 0;
}