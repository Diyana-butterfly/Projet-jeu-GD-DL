/**********************************************************************
*Auteur         : GANDA & DAKEY
*Parcours       : EPL G�nie Logiciel S3
*Ann�es         : 2024-2025
*Description    : Programme de jeu de devinette
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"
#include "jeu.h"
#include "difficulte.h"
#include "pseudo.h"
#include "stat.h"
#include <locale.h>

int main()
{

    setlocale(LC_CTYPE,"");


    printf("\t\t\t\t\tBIENVENUE SUR NOTRE JEU DE DEVINETTE\n");

    char pseudo[100];
    printf("Entrez votre pseudo : ");
    scanf("%s", pseudo);
    enregistrerPseudo(pseudo);//appel de la fonction enregistrerPseudo pour l'enregistrement des pseudos


    int max = 0, tentativesMax = 0;
    char decision[4];

    do
    {
        choisirNiveau(&max, &tentativesMax);
        jeuDeDevinette(max, tentativesMax);

        printf("Voulez vous rejouez (O / N) \n");
        scanf("%s", decision);
    }
    while(strcmp(decision, "O") == 0 || strcmp(decision, "o") == 0);  // Comparaison des cha�nes de caract�res pour d�cider de rejouer
    printf("Merci d'avoir jou� !\n");
    return 0;
}

