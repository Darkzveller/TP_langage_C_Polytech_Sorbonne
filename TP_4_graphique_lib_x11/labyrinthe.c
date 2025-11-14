#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
// Commande gcc : 
// rm launch.out affichage.o labyrinthe.o lecture.o 
// ls -l *.o *.out && 
// gcc -c labyrinthe.c && gcc -c affichage.c && gcc affichage.o labyrinthe.o -o launch.out -lX11 && ./launch.out
// gcc -c labyrinthe.c && gcc -c affichage.c && gcc -c lecture.c && gcc affichage.o labyrinthe.o lecture.o -o launch.out -lX11 && ./launch.out

int coord_x_depart;
int coord_y_depart;
int coord_x_arrivee;
int coord_y_arrivee;
int tab_representative_labyrinthe[TAILLE_X][TAILLE_Y];

int main(void) {

    /* Charger le labyrinthe depuis le fichier */
    if (!build_labyrinthe("laby1.txt", tab_representative_labyrinthe)) {
        printf("Error chargement fichier\n");
        return 1;
    }

    /* Initialisation affichage */
    if (!initAffichage()) {
        printf("Error initialisation de l'affichage\n");
        return 1;
    }

    // Coordonnées de départ et d'arrivée qu'on archive
    int couple_cordonne_depart[2] = {coord_x_depart, coord_y_depart};
    int couple_cordonne_arrivee[2] = {coord_x_arrivee, coord_y_arrivee};

    //Affiche labyrinthe
    afficheLabyrinthe(tab_representative_labyrinthe, couple_cordonne_depart, couple_cordonne_arrivee, 0);

    return 0;
}

// Renvoie les coordonnées de la case voisine à partir d'une case (x, y) et d'une direction d
// d = 0 : Nord, 1 : Est, 2 : Sud, 3 : Ouest
 void coord_case_voisine(int coord_x_actu, int coord_y_actu, int direction_voulue, int *coord_x_voisine, int *coord_y_voisine)
{
    if (direction_voulue == 0) {  
        // Nort
        *coord_x_voisine = coord_x_actu;
        *coord_y_voisine = coord_y_actu - 1;

    } else if (direction_voulue == 1) {     
        // Est
        *coord_x_voisine = coord_x_actu + 1;
        *coord_y_voisine = coord_y_actu;

    } else if (direction_voulue == 2) {    
        // Sud       
        *coord_x_voisine = coord_x_actu;
        *coord_y_voisine = coord_y_actu + 1;

    } else if (direction_voulue == 3) {    
        // Ouest
        *coord_x_voisine= coord_x_actu - 1;
        *coord_y_voisine= coord_y_actu;

    }else {
    *coord_x_voisine = coord_x_actu;
    *coord_y_voisine = coord_y_actu;
}
}  
