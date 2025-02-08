#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pseudo.h"

void enregistrerPseudo(const char* pseudo) {
    FILE* fichier = fopen("pseudos.txt", "a+");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    // Lire tout le fichier pour vérifier les doublons
    char ligne[100];
    int existe = 0;
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Supprimer le caractère de nouvelle ligne
        ligne[strcspn(ligne, "\n")] = 0;
        if (strcmp(ligne, pseudo) == 0) {
            existe = 1;
        }
    }

    // Si le pseudo n'existe pas, l'ajouter
    if (!existe) {
        fprintf(fichier, "%s\n", pseudo);
    } else {
        printf("Le pseudo existe déjà.\n");
    }

    fclose(fichier);
}

void consulterPseudos() {
    FILE* fichier = fopen("pseudos.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    char ligne[100];
    printf("Archives des pseudos :\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }

    fclose(fichier);
}
