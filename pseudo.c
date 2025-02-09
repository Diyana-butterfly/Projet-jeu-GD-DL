#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pseudo.h"

// Enregistrer un nouveau pseudo,mot de passe et date
int enregistrerPseudo(const char* pseudo, const char* motDePasse) {
    FILE* fichier = fopen("pseudos.txt", "a+");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 0;
    }

    // Lire tout le fichier pour vérifier les doublons
    char ligne[200];
    int existe = 0;
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Supprimer le caractère de nouvelle ligne
        ligne[strcspn(ligne, "\n")] = 0;
        char* token = strtok(ligne, ":");
        if (token && strcmp(token, pseudo) == 0) {
            existe = 1;
            break;
        }
    }

    if (!existe) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        fprintf(fichier, "%s - %s - %02d-%02d-%d\t", pseudo, motDePasse, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    }

    fclose(fichier);
    return !existe;
}
//Vérifier si un pseudo et mot de passe existe déjà
int verifierPseudoEtMotDePasse(const char* pseudo, const char* motDePasse) {
    FILE* fichier = fopen("pseudos.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 0;
    }

    char ligne[200];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        ligne[strcspn(ligne, "\n")] = 0;
        char* token = strtok(ligne, ":");
        if (token && strcmp(token, pseudo) == 0) {
            token = strtok(NULL, ":");
            if (token && strcmp(token, motDePasse) == 0) {
                fclose(fichier);
                return 1;
            } else {
                fclose(fichier);
                return 0;
            }
        }
    }

    fclose(fichier);
    return 0;
}
// Consulter les pseudo enrégistrés
void consulterPseudos() {
    FILE* fichier = fopen("pseudos.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    char ligne[200];
    printf("Archives des pseudos :\n");
    printf("Pseudo - Mot de passe - Date\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("%s", ligne);
    }

    fclose(fichier);
}
