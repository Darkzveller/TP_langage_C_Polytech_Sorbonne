#ifndef METRO_H
#define METRO_H

/* Structure représentant une station */
typedef struct {
    char *nom;        /* nom de la station (alloué dynamiquement) */
    double latitude;  /* latitude de la station */
    double longitude; /* longitude de la station */
} t_station;

/* Structure représentant un réseau de métro */
//Ancienne version
// typedef struct {
//     t_station *stations; /* tableau dynamique de stations */
//     int nb_stations;     /* nombre de stations */
// } t_metro;

/* Structure représentant une ligne de métro */
typedef struct {
    char *nom;           /* nom de la ligne (allocation dynamique) */
    char couleur[10];    /* couleur de la ligne (ex: "#FFCC00") */
    int attente;         /* temps moyen d'attente (en minutes) */
} t_line;

typedef struct {
    t_station *stations; /* tableau dynamique de stations */
    int nb_stations;

    t_line *lignes;      /* tableau dynamique de lignes */
    int nb_lignes;
} t_metro;


/* Prototype de readStation */
void readStation(FILE *f, t_station *station);
/* Prototype */
int readMetro(const char *filename, t_metro *metro);
t_station *findStation(const t_metro *metro, const char *nom);
void readLine(FILE *f, t_line *line);


#endif /* METRO_H */
