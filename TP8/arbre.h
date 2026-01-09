#ifndef __ARBRE_H__
#define __ARBRE_H__

typedef struct t_noeud
{

    char *chaine;
    double valeur;
    struct t_noeud *fil_gauche;
    struct t_noeud *fil_droit;

} t_noeud;

t_noeud *creerNoeud(float val, char *ch, t_noeud *filsG, t_noeud *filsD);

t_noeud *creerNoeudOp(t_noeud *filsG, char *ch, t_noeud *filsD);
t_noeud *creerFeuilleReel(float val);
t_noeud *creerFeuilleVar(char *ch);
void detruireArbre(t_noeud *arbre);
int nbFils(t_noeud* noeud);



#endif