#include <stdio.h>
#include <string.h>

/**
 Compare deux chaînes de caractères en utilisant l'indexation [].
 Parametres :
  s1 : première chaîne
  s2 : deuxième chaîne
 Retourne :
 0 si s1 == s2
 Une valeur négative si s1 < s2
 Une valeur positive si s1 > s2
 */
int strcmp1(char* s1, char* s2) {
    int i = 0;

    // On compare les caractères tant qu'ils sont identiques
    while (s1[i] == s2[i]) {
        // Si on tombe sur le caractère nul,
        // cela veut dire que les chaînes sont identiques
        if (s1[i] == '\0') {
            return 0;
        }
        i++;
    }

    // s1[i] != s2[i] → on a trouvé la première différence
    return s1[i] - s2[i];
}

/*
  Compare deux chaînes en utilisant l'arithmétique des pointeurs.
  Parametres :
    s1 : pointeur vers la première chaîne
    s2 : pointeur vers la deuxième chaîne
  s1 et s2 sont incrémentés pour parcourir la mémoire.
 */
int strcmp2(char* s1, char* s2) {
    // On compare la VALEUR pointée par s1 avec la VALEUR pointée par s2
    while (*s1 == *s2) {
        
        // Si la valeur pointée est le caractère nul, c'est la fin des chaînes
        // et elles sont égales.
        if (*s1 == '\0') {
            return 0;
        }

        // On incrémente les adresses (les pointeurs) pour passer au caractère suivant
        s1++;
        s2++;
    }

    // Si on sort de la boucle, les caractères sont différents.
    // On retourne la différence des valeurs pointées.
    return (*s1 - *s2);
}

int main() {

    char chaine1[100];
    char chaine2[100];

    printf("Entrez la première chaîne : ");
    scanf("%99s", chaine1);

    printf("Entrez la deuxième chaîne : ");
    scanf("%99s", chaine2);

    printf("\nRésultats :\n");

    int r1 = strcmp1(chaine1, chaine2);
    int r2 = strcmp2(chaine1, chaine2);
    int r3 = strcmp(chaine1, chaine2);  // vraie fonction

    printf("strcmp1 = %d\n", r1);
    printf("strcmp2 = %d\n", r2);
    printf("strcmp_original  = %d\n", r3);

    return 0;
}
