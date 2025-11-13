// commande a tap� : gcc selection.c -o selection; .\selection.exe

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
    // V�rifie qu'on a bien ouvert le fihcier valeurs.txt
    if (fp == NULL)
    {
        printf("Le fichier valeurs.txt n'a pas pu �tre ouvert\n");
        return EXIT_FAILURE;
    }

    printf("Le fichier valeurs.txt existe\n");


    // Lecture du nbr val pr�sent
    fscanf(fp,"%d",&nbr_val_present_fichier_txt);
    printf("Il y a %d valeurs dans ce fichiers a lire \n", nbr_val_present_fichier_txt);

    // Stocke les valeurs pr�sents dans le tableau de r�el
    for(int i = 0; i < nbr_val_present_fichier_txt; i++)
    {
        fscanf(fp,"%f",&stock_nbr_reel[i]);
        printf("%f",stock_nbr_reel[i]);
        printf("\n");

    }
// Fermeture du fichier valeurs.txt
    fclose(fp);


    // On s�pare le stockage des r�els, du traitement de celui ci
    printf("\n\n\n\n");
    /*
    Algorithme TRI_PAR_SELECTION
    Pour i allant de 0 � nbr donn�e pr�sente dans le fichier
        - indice_p >- j
        - Pour j allant de i+1 � nbr donn�e pr�sente dans le fichier
            Si  T[indice_p] > T[j] alors
                indice_p <- j
        - �changer T[i] et T[indice_p]
    */
    for(int i = 0; i < nbr_val_present_fichier_txt; i++)
    {

        for(int j = i + 1; j < nbr_val_present_fichier_txt; j++)
        {
            if(stock_nbr_reel[indice_p]>stock_nbr_reel[j])
            {
                indice_p = j;

            }
            temp = stock_nbr_reel[indice_p];
            stock_nbr_reel[indice_p] = stock_nbr_reel[i];
            stock_nbr_reel[i]= temp;
        }
    }

    FILE* fichier_val_trier = NULL;
    fichier_val_trier = fopen("valeurs-triees.txt","w");
    if (fichier_val_trier == NULL)
    {
        printf("Le fichier valeurs-triees.txt n'a pas pu �tre ouvert\n");
        return EXIT_FAILURE;
    }

    printf("Voici ce qui a �t� ecris dans valeur-triees.txt\n");

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
