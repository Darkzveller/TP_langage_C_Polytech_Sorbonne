#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metro.h"


int readMetro(const char *filename, t_metro *metro) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Erreur ouverture fichier");
        return 0;
    }

    /* Lecture du nombre de stations */
    fscanf(f, "%d", &metro->nb_stations);
    fgetc(f); /* lecture du '\n' après l'entier */

    /* Allocation du tableau de stations */
    metro->stations = malloc(metro->nb_stations * sizeof(t_station));
    if (metro->stations == NULL) {
        fclose(f);
        return 0;
    }

    /* Lecture de chaque station */
    for (int i = 0; i < metro->nb_stations; i++) {
        readStation(f, &metro->stations[i]);
    }

    fclose(f);
    return 1;
}

void readStation(FILE *f, t_station *station) {
    char buffer[256];
    float lat, lon;

    /* Lecture du nom jusqu'au ':' */
    fscanf(f, "%[^:]", buffer);

    /* Lecture des deux flottants + fin de ligne */
    fscanf(f, ":%f:%f\n", &lat, &lon);

    /* Allocation mémoire pour le nom */
    station->nom = malloc((strlen(buffer) + 1) * sizeof(char));
    if (station->nom != NULL) {
        strcpy(station->nom, buffer);
    }

    station->latitude = lat;
    station->longitude = lon;
}

t_station *findStation(const t_metro *metro, const char *nom) {
    for (int i = 0; i < metro->nb_stations; i++) {
        if (strcmp(metro->stations[i].nom, nom) == 0) {
            return &metro->stations[i];
        }
    }
    return NULL;
}
