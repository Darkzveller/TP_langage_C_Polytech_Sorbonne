

// int algorithme_needlman_wunsch(char *seq_adn_1, char *seq_adn_2)
// {
//     // Implémentation de l'algorithme de Needleman-Wunsch
//     // Cette fonction calcule et retourne le score d'alignement global entre seq1 et seq2
//     // Pour l'instant, cette fonction est un stub et retourne 0

//     int len_seq_adn_1 = strlen(seq_adn_1)+1;
//     int len_seq_adn_2 = strlen(seq_adn_2)+1;

//     // Création de la matrice de score
//     int score_matrice[len_seq_adn_1*len_seq_adn_2];
//     // Initialisation de la matrice
//     for (int i = 0; i < len_seq_adn_1-1; i++)
//     {
//         score_matrice[i*len_seq_adn_2] = 0; // Initialisation de la première colonne
//     }
//      for (int j = 0; j < len_seq_adn_2-1; j++)
//     {
//         score_matrice[j][] = 0; // Initialisation de la première colonne
//     }
//     return 0;
// }