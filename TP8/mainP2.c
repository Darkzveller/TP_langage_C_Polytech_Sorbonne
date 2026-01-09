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
    arbre = creerArbreDepuisInfixee(saisie_caractere);

    printf("Affichage post-fixee : ");
    afficherArbrePostFixe(arbre);
    printf("\n");

    printf("Affichage infixeer : ");
    afficherArbreInfixe(arbre);
    printf("\n");

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
    int res = evaluer(arbre);
    if (res)
    {
        printf("L'arbre a pu etre evaluer\n");
    }
    else
    {
        printf("L'arbre n'a pas pu etre evaluer\n");
    }
    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
    /*printf("Test de remplacer Neud : remplacement du nœud racine par la valeur 42\n");

    remplacerNoeud(arbre, 42);

    printf("Apres remplacement :\n");
    printf("Affichage post-fixee : ");
    afficherArbrePostFixe(arbre);
    printf("\n");

    printf("Affichage infixee : ");
    afficherArbreInfixe(arbre);
    printf("\n");

    printf("Nombre de fils de la racine : %d\n", nbFils(arbre));
    printf("Valeur du noeud racine : %.2f\n", arbre->valeur);
*/

    t_noeud *arbre1 = creerNoeudOp(creerFeuilleReel(1.5708), "sin", NULL); // sin(pi/2)
    res = evaluer_v2(arbre1);
    if (res)
    {
        printf("L'arbre a pu etre evaluer\n");
    }
    else
    {
        printf("L'arbre n'a pas pu etre evaluer\n");
    }

    printf("Affichage in-fixee : ");
    afficherArbreInfixe(arbre1);
    printf("\n");

    printf("Valeur du noeud racine : %.2f\n", arbre1->valeur);

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
    detruireArbre(arbre);
    detruireArbre(arbre1);

    printf("Arbres detruits.\n");

    return 0;
}