#ifndef __EQUATION_H__
#define __EQUATION_H__

void afficherArbrePostFixe(t_noeud* arbre);

void afficherArbreInfixe(t_noeud* arbre);
int evaluer(t_noeud* arbre);
void remplacerNoeud(t_noeud* arbre, float val);

int evaluer_v2(t_noeud *arbre);


#endif