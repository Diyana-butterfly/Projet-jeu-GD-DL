#include <stdio.h>
#include "difficulte.h"

void choisirNiveau(int* max, int* tentativesMax) {
    int choix;
    /*printf("Choisissez un niveau de difficult� :\n");
    printf("1. D�butant (1 � 100, tentatives max: 10)\n");
    printf("2. Moyen (1 � 500, tentatives max: 20)\n");
    printf("3. L�gende (1 � 2000, tentatives max: 25)\n");
    printf("4. Master (personnaliser la borne maximale et les tentatives)\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            *max = 100;
            *tentativesMax = 10;
            break;
        case 2:
            *max = 500;
            *tentativesMax = 20;
            break;
        case 3:
            *max = 2000;
            *tentativesMax = 25;
            break;
        case 4:
            printf("Entrez la borne maximale : ");
            scanf("%d", max);
            printf("Entrez le nombre maximum de tentatives : ");
            scanf("%d", tentativesMax);
            break;
        default:
            printf("Choix invalide.\n");
            break; */




        printf("Choisissez un niveau de difficult� :\n");
        printf("1. D�butant (1 � 100, tentatives max: 10)\n");
        printf("2. Moyen (1 � 500, tentatives max: 20)\n");
        printf("3. L�gende (1 � 2000, tentatives max: 25)\n");
        printf("4. Master (personnaliser la borne maximale et les tentatives)\n");
        printf("5. Voir archive des pseudos \n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            max = 100;
            tentativesMax = 10;
            break;
        case 2:
            max = 500;
            tentativesMax = 20;
            break;
        case 3:
            max = 2000;
            tentativesMax = 25;
            break;
        case 4:
            printf("Entrez la borne maximale : ");
            scanf("%d", &max);
            printf("Entrez le nombre maximum de tentatives : ");
            scanf("%d", &tentativesMax);
            break;
        case 5:
            consulterPseudos();

        default:
            printf("Choix invalide.\n");
        return 1;
        }
    }

