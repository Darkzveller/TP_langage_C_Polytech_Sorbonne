# Compilateur et options
# --------------------------
CC = gcc                 # Le compilateur C à utiliser (ici GCC)
CFLAGS = -Wall           # Options de compilation : -Wall active tous les avertissements
LIBS = -lX11 -lm         # Bibliothèques à lier (ici X11 pour l'affichage graphique)
LIBSDIR =                # Répertoires supplémentaires pour les bibliothèques (vide ici)

# Nom du fichier main à utiliser (par défaut mainP1.c)
MAIN = mainP1.c
# SRC_NO_MAIN contient tous les fichiers .c du dossier sauf mainP1.c et mainP2.c
# $(wildcard *.c) liste tous les fichiers .c, et $(filter-out ...) retire les deux fichiers main
SRC_NO_MAIN = $(filter-out mainP1.c mainP2.c, $(wildcard *.c))

# Fichiers du projet
SRC = $(MAIN) $(SRC_NO_MAIN) # Liste de tous les fichiers source .c du dossier courant
OBJ = $(SRC:.c=.o)       # Liste des fichiers objets correspondants aux .c
EXEC = strcmp.out          # Nom de l'exécutable final

# Règle par défaut : tout compiler
all: $(EXEC)             # La cible 'all' dépend de l'exécutable
                         # Quand tu tapes 'make', c'est cette règle qui est exécutée par défaut

# Compilation de chaque .c en .o
%.o: %.c                 # Règle générique : comment transformer un .c en .o
	$(CC) $(CFLAGS) -c $< -o $@  
                         # $< = le fichier source (.c)
                         # $@ = le fichier cible (.o)
                         # Cette ligne compile chaque .c en .o

# Edition de liens pour créer l'exécutable
$(EXEC): $(OBJ)          # L'exécutable dépend de tous les objets
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBSDIR)  
                         # $@ = nom de l'exécutable (strcmp.out)
                         # $^ = tous les fichiers objets
                         # Ajoute les bibliothèques nécessaires (-lX11)
                         # Cette ligne assemble les .o en exécutable

# Nettoyage des fichiers objets uniquement
clean:
	rm -f *.o *.out              
# Supprime tous les fichiers objets .o et .out

# Nettoyage complet : fichiers objets + exécutable
mproper:
	rm -f $(EXEC) *.o *.out      		
# Supprime l'exécutable et tous les fichiers objets

# Règle pour compiler et lancer le programme
run: $(EXEC)             # La cible 'run' dépend de l'exécutable
	./$(EXEC)             
# Exécute le programme

# Dépendances explicites
pile.o: pile.c pile.h
mainP1.o: mainP1.c pile.h 
mainP2.o: mainP2.c pile.h 
