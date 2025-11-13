// commande a tapé : gcc bulles.c -o bulles; .\bulles.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


#define TAILLE_TABLEAU 100
float stock_nbr_reel[TAILLE_TABLEAU] = {0};
int nbr_val_present_fichier_txt = 0;
float temp = 0;
int indice_p = 0;

int main(void)
{
    // Affiche hello World
    printf("Hello world!\n");

    // Ouverture du fihcier code1 en mode lecteur
    FILE *fp = fopen("valeurs.txt", "r");
    // Vérifie qu'on a bien ouvert le fihcier valeurs.txt
    if (fp == NULL)
    {
        printf("Le fichier valeurs.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    printf("Le fichier valeurs.txt existe\n");


    // Lecture du nbr de valeur présent
    fscanf(fp,"%d",&nbr_val_present_fichier_txt);
    printf("Il y a %d valeurs dans ce fichiers a lire \n", nbr_val_present_fichier_txt);

    // Stocke les valeurs présents dans le tableau de réel
    for(int i = 0; i < nbr_val_present_fichier_txt; i++)
    {
        fscanf(fp,"%f",&stock_nbr_reel[i]);
        printf("%f",stock_nbr_reel[i]);
        printf("\n");

    }
// Fermeture du fichier valeurs.txt
    fclose(fp);


    // On sépare le stockage des réels, du traitement de celui ci
    printf("\n\n\n\n");


    for(int i = 0; i <= nbr_val_present_fichier_txt-1; i++)
    {
        for(int j = 0; j <= nbr_val_present_fichier_txt-i-1; j++)
        {
            if(stock_nbr_reel[j-1]>stock_nbr_reel[j])
            {
                temp = stock_nbr_reel[j-1];
                stock_nbr_reel[j-1] = stock_nbr_reel[j];
                stock_nbr_reel[j]= temp;
            }
            if(stock_nbr_reel[j-1]==stock_nbr_reel[j])
            {
                break;
            }
        }
    }

    FILE* fichier_val_trier = NULL;
    fichier_val_trier = fopen("valeurs-triees.txt","w");
    if (fichier_val_trier == NULL)
    {
        printf("Le fichier valeurs-triees.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    printf("Voici ce qui a été ecris dans valeur-triees.txt\n");

    for(int i = 0; i < nbr_val_present_fichier_txt; i++)
    {
        printf("%f",stock_nbr_reel[i]);
        printf("\n");
        fprintf(fichier_val_trier,"%f\n",stock_nbr_reel[i]);

    }

    fclose(fichier_val_trier);

    printf("Fini");

    return 0;

}
