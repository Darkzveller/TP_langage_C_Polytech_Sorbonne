#include <stdio.h>
#include <stdlib.h>
#include "metro.h"

int main(void)
{
    printf("Vous avez lancer %s\n\n", __FILE__); // __FILE__ contient le nom du fichier source
    printf("\n--------------------------------------------------------------------------------------------------------------\n\n");

    t_metro metro;

    if (!readMetro("paris-stations.txt", &metro))
    {   
        printf("Erreur lors de la lecture du metro\n");
        return 1;
    }

    int index = 99; /* station n°100 */

    if (index < metro.nb_stations)
    {
        printf("Station 100 : %s (%.6f, %.6f)\n",
               metro.stations[index].nom,
               metro.stations[index].latitude,
               metro.stations[index].longitude);
    }
    else
    {
        printf("Station inexistante\n");
    }
    /* Recherche de Jussieu */
    t_station *s = findStation(&metro, "Jussieu");

    if (s != NULL)
    {
        printf("Station Jussieu : (%.6f, %.6f)\n",
               s->latitude, s->longitude);
    }
    else
    {
        printf("Station Jussieu non trouvée\n");
    }

if (metro.nb_lignes >= 10)
{
    printf("Ligne 10 : %s (%s)\n",
           metro.lignes[9].nom,
           metro.lignes[9].couleur);
}
else
{
    printf("Il n'y a pas 10 lignes\n");
}

    /* Libération mémoire */
    for (int i = 0; i < metro.nb_stations; i++)
    {
        free(metro.stations[i].nom);
    }
    free(metro.stations);

    
    return 0;
}
