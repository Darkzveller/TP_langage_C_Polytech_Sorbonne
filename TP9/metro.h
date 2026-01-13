#ifndef METRO_H
#define METRO_H

/* Structure représentant une station */
typedef struct {
    char *nom;        /* nom de la station (alloué dynamiquement) */
    double latitude;  /* latitude de la station */
    double longitude; /* longitude de la station */
} t_station;

/* Structure représentant un réseau de métro */
typedef struct {
    t_station *stations; /* tableau dynamique de stations */
    int nb_stations;     /* nombre de stations */
} t_metro;
/* Prototype de readStation */
void readStation(FILE *f, t_station *station);
/* Prototype */
int readMetro(const char *filename, t_metro *metro);



#endif /* METRO_H */
