// commande a tapé : gcc sudoku.c -o sudoku; .\sudoku.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define TAILLE_GRILLE 9

int grille[9][9]= {0};
uint8_t erreur = 0;

int main()
{
    // Affiche hello World
    printf("Hello world!\n");

    // Ouverture du fihcier code1 en mode lecteur
    FILE *fp = fopen("grille.txt", "r");
    // Vérifie qu'on a bien ouvert le fihcier valeurs.txt
    if (fp == NULL)
    {
        printf("Le fichier grille.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    printf("Le fichier grille.txt existe\n");



    // Lecture de la grille
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++)
        {
            fscanf(fp, "%d", &grille[ligne][colonne]);
        }
    }

    fclose(fp);

    // Affichage de la grille
    printf("Voici la grille lue :\n");
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {

        for (int colonne = 0; colonne <TAILLE_GRILLE; colonne++)
        {
            printf("%d ", grille[ligne][colonne]);
        }
        printf("\n");
    }



    // Affichage des - et |
    printf("\nVoici la grille lue (esthetic is good) :\n");

    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        printf("-------------------------------------\n");

        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++)
        {
            printf("| %d ", grille[ligne][colonne]);
        }
        printf("|\n");
    }
    printf("-------------------------------------\n");



    // Vérification des lignes
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {

        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++)
        {
            int valeur_case_actuel = grille[ligne][colonne];
            //printf("valeur_case_actuel %d ",valeur_case_actuel);

            for(int verif_repet = colonne+1; verif_repet < TAILLE_GRILLE; verif_repet++)
            {
                int valeur_case_a_verifier =grille[ligne][verif_repet];

                //printf(" valeur_case_a_verifier %d ",valeur_case_a_verifier);

                if (valeur_case_actuel==valeur_case_a_verifier)
                {
                    printf("Erreur : doublon du chiffre %d sur la ligne %d\n", valeur_case_actuel, (ligne +1) );
                    erreur = 1;
                }
            }
        }
    }


    // Vérification des colonne
    for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++)
    {

        for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++)
        {
            int valeur_case_actuel = grille[ligne][colonne];
            //printf("valeur_case_actuel %d ",valeur_case_actuel);

            for(int verif_repet = ligne+1; verif_repet < TAILLE_GRILLE; verif_repet++)
            {
                int valeur_case_a_verifier =grille[verif_repet][colonne];

                //printf(" valeur_case_a_verifier %d ",valeur_case_a_verifier);

                if (valeur_case_actuel==valeur_case_a_verifier)
                {
                    printf("Erreur : doublon du chiffre %d sur la colonne %d\n", valeur_case_actuel, (colonne +1) );
                    erreur += 1;
                }
            }
        }
    }


// Vérification des sous-grilles 3x3
    for (int ligne_base = 0; ligne_base < TAILLE_GRILLE; ligne_base += 3)
    {
        for (int colonne_base = 0; colonne_base < TAILLE_GRILLE; colonne_base += 3)
        {

            // Parcours de chaque case dans la sous-base
            for (int ligne_sous_base = 0; ligne_sous_base < 3; ligne_sous_base++)
            {
                for (int colonne_sous_base = 0; colonne_sous_base < 3; colonne_sous_base++)
                {

                    int valeur_case_actuelle = grille[ligne_base + ligne_sous_base][colonne_base + colonne_sous_base];

                    // Comparer avec toutes les cases restantes dans la sous-grille
                    for (int ligne_comp = ligne_sous_base; ligne_comp < 3; ligne_comp++)
                    {

                        int debut_colonne_comp;
                        if (ligne_comp == ligne_sous_base)
                        {
                            debut_colonne_comp = colonne_sous_base + 1;  // Commencer après la case actuelle si même ligne
                        }
                        else
                        {
                            debut_colonne_comp = 0;  // Sinon, commencer début de ligne
                        }

                        for (int colonne_comp = debut_colonne_comp; colonne_comp < 3; colonne_comp++)
                        {
                            int valeur_case_a_verifier = grille[ligne_base + ligne_comp][colonne_base + colonne_comp];

                            if (valeur_case_actuelle == valeur_case_a_verifier)
                            {
                                printf("Erreur : doublon du chiffre %d dans la sous-grille (%d,%d)\n",
                                       valeur_case_actuelle, ligne_base / 3 + 1, colonne_base / 3 + 1);
                                erreur = 1;
                            }
                        }
                    }
                }
            }
        }
    }


    if (!erreur)
    {
        printf("\nToutes les lignes respectent la condition du Sudoku\n");
    }
    fclose(fp);
    printf("Fini");
    return 0;
}
