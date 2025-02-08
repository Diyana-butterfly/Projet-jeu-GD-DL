#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stat.h"

void enregistrerTentative(int tentative) {
    FILE* fichier = fopen("tentatives.dat", "ab");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    fwrite(&tentative, sizeof(int), 1, fichier);
    fclose(fichier);
}

void calculerEcartType() {
    FILE* fichier = fopen("tentatives.dat", "rb");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
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
        printf("Ecart-type des tentatives : %.2f\n", ecartType);
    } else {
        printf("Pas assez de données pour calculer l'écart-type.\n");
    }
}

void consulterTentatives() {
    FILE* fichier = fopen("tentatives.dat", "rb");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    int tentative;
    printf("Archives des tentatives :\n");
    while (fread(&tentative, sizeof(int), 1, fichier)) {
        printf("%d\n", tentative);
    }

    fclose(fichier);
}
