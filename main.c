/*
*Auteur : GANDA & DAKEY
*
*Parcours : EPL G�nie Logiciel S3
*Ann�es : 2024-2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "jeu.h"
#include "difficulte.h"
#include "pseudo.h"
#include "stat.h"
#include <locale.h>

int main()
{

    setlocale(LC_CTYPE,"");

    char pseudo[100];
    printf("Entrez votre pseudo : ");
    scanf("%s", pseudo);
    enregistrerPseudo(pseudo);


    int choix, max, tentativesMax;
    char decision[4];

    do
    {
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
        jeuDeDevinette(max, tentativesMax);

        printf("Voulez vous rejouez (O / N) \n");
        scanf("%s", decision);
    }
    while(strcmp(decision, "O") == 0 || strcmp(decision, "o") == 0);  // Comparaison des cha�nes de caract�res pour d�cider de rejouer
    printf("Merci d'avoir jou� !\n");
    return 0;
}

