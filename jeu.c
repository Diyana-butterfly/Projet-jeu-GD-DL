#include <stdio.h>
#include "random.h"
#include "jeu.h"

void jeuDeDevinette(int max, int tentativesMax) {
    int nombreMystere = genererNombreAleatoire(max);
    int nombreEntre, coups = 0;

    printf("Devinez le nombre mystère entre 1 et %d \n", max);

    do {
        printf("Entrez un nombre : ");
        scanf("%d", &nombreEntre);
        coups++;

        if (nombreEntre < nombreMystere) {
            printf("C'est plus !\n");
        } else if (nombreEntre > nombreMystere) {
            printf("C'est moins !\n");
        } else {
            printf("Bravo, vous avez trouvé le nombre mystère en %d coups !\n", coups);
        }

        if (coups >= tentativesMax) {
            printf("Désolé, vous avez atteint le nombre maximum de tentatives.\n");
            break;
        }
    } while (nombreEntre != nombreMystere);
}
