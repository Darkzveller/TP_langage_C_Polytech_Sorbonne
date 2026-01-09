#include <stdio.h>
#include "arbre.h"
#include "lectureInfixee.h"

int main()
{
    printf("Vous avez lancer %s\n\n", __FILE__); // __FILE__ contient le nom du fichier source
    printf("caca test\n");
    
    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");

    t_noeud *arbre = creerNoeudOp(creerFeuilleReel(12), "+", creerNoeudOp(creerFeuilleReel(4), "*", creerFeuilleVar("x")));

    printf("Arbre 12 + 4*x cree.\n");

    // Test nbFils
    printf("Nombre de fils de la racine : %d\n", nbFils(arbre)); // doit afficher 2

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
    t_noeud *gauche = creerNoeudOp(creerFeuilleReel(12), "+", creerFeuilleVar("x")); // 12 + x
    t_noeud *droite = creerNoeudOp(
        creerNoeudOp(creerFeuilleReel(6), "/", creerFeuilleReel(25)),
        "^",
        creerFeuilleReel(2)); // (6 / 25)^2

    // Racine *
    t_noeud *arbre2 = creerNoeudOp(gauche, "*", droite);

    printf("Arbre (12 + x) * (6 / 25)^2 cree.\n");

    // Test nbFils
    printf("Nombre de fils de la racine : %d\n", nbFils(arbre2)); // doit afficher 2

    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");

    detruireArbre(arbre);
    detruireArbre(arbre2);

    printf("Arbres detruits.\n");

    return 0;
}