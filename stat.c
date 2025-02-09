#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stat.h"

// Enregistrer une tentative pour un utilisateur sp�cifique
void enregistrerTentative(int tentative, const char* pseudo) {
    char fichierNom[100];
    snprintf(fichierNom, sizeof(fichierNom), "%s_tentatives.dat", pseudo);
    FILE* fichier = fopen(fichierNom, "ab");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier de tentatives.\n");
        return;
    }

    fwrite(&tentative, sizeof(int), 1, fichier);
    fclose(fichier);
}

// Calculer l'�cart-type pour un utilisateur sp�cifique
void calculerEcartType(const char* pseudo) {
    char fichierNom[100];
    snprintf(fichierNom, sizeof(fichierNom), "%s_tentatives.dat", pseudo);
    FILE* fichier = fopen(fichierNom, "rb");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier de tentatives.\n");
        return;
    }

    int tentative, count = 0;
    double sum = 0, sumSquares = 0;

    while (fread(&tentative, sizeof(int), 1, fichier)) {
        sum += tentative;
        sumSquares += tentative * tentative;
        count++;
    }

    fclose(fichier);

    if (count > 1) {
        double mean = sum / count;
        double variance = (sumSquares / count) - (mean * mean);
        double ecartType = sqrt(variance);
        printf("Ecart-type des tentatives pour %s : %.2f\n", pseudo, ecartType);
    } else {
        printf("Pas assez de donn�es pour calculer l'�cart-type pour %s.\n", pseudo);
    }
}

// Consulter les tentatives pour un utilisateur sp�cifique
void consulterTentatives(const char* pseudo) {
    char fichierNom[100];
    snprintf(fichierNom, sizeof(fichierNom), "%s_tentatives.dat", pseudo);
    FILE* fichier = fopen(fichierNom, "rb");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier de tentatives.\n");
        return;
    }

    int tentative;
    printf("Archives des tentatives pour %s :\n", pseudo);
    while (fread(&tentative, sizeof(int), 1, fichier)) {
        printf("%d\n", tentative);
    }

    fclose(fichier);
}
