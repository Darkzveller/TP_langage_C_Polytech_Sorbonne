#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metro.h"

int readMetro(const char *filename, t_metro *metro)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        perror("Erreur ouverture fichier");
        return 0;
    }

    /* Lecture du nombre de stations */
    fscanf(f, "%d", &metro->nb_stations);
    fgetc(f); /* lecture du '\n' après l'entier */

    /* Allocation du tableau de stations */
    metro->stations = malloc(metro->nb_stations * sizeof(t_station));
    if (metro->stations == NULL)
    {
        fclose(f);
        return 0;
    }
        /* Lecture de chaque station */
    for (int i = 0; i < metro->nb_stations; i++)
    {
        readStation(f, &metro->stations[i]);
    }

    /* Lecture des lignes */
    fscanf(f, "%d", &metro->nb_lignes);
    fgetc(f); /* saut de ligne */
    
    metro->lignes = malloc(metro->nb_lignes * sizeof(t_line));
    if (metro->lignes == NULL)
    {
        fclose(f);
        return 0;
    }

    for (int i = 0; i < metro->nb_lignes; i++)
    {
        readLine(f, &metro->lignes[i]);
    }

    fclose(f);
    return 1;
}

void readStation(FILE *f, t_station *station)
{
    char buffer[256];
    float lat, lon;

    /* Lecture du nom jusqu'au ':' */
    fscanf(f, "%[^:]", buffer);

    /* Lecture des deux flottants + fin de ligne */
    fscanf(f, ":%f:%f\n", &lat, &lon);

    /* Allocation mémoire pour le nom */
    station->nom = malloc((strlen(buffer) + 1) * sizeof(char));
    if (station->nom != NULL)
    {
        strcpy(station->nom, buffer);
    }

    station->latitude = lat;
    station->longitude = lon;
}

t_station *findStation(const t_metro *metro, const char *nom)
{
    for (int i = 0; i < metro->nb_stations; i++)
    {
        if (strcmp(metro->stations[i].nom, nom) == 0)
        {
            return &metro->stations[i];
        }
    }
    return NULL;
}

void readLine(FILE *f, t_line *line)
{
    char buffer[256];
    int attente;

    /* Lecture du nom jusqu'au ':' */
    if (fscanf(f, " %255[^:]:", buffer) != 1) {
        line->nom = NULL;  // si erreur, mettre NULL
        line->couleur[0] = '\0';
        line->attente = 0;
        return;
    }

    /* Allocation dynamique pour le nom */
    line->nom = malloc(strlen(buffer) + 1);
    if (line->nom != NULL)
    {
        strcpy(line->nom, buffer);
    }

    /* Lecture de la couleur et du temps d'attente */
    if (fscanf(f, "%9[^:]:%d\n", line->couleur, &attente) != 2) {
        line->couleur[0] = '\0';
        line->attente = 0;
    } else {
        line->attente = attente;
    }
}
