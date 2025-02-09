#include <stdio.h>
#include "random.h"
#include "jeu.h"
#include "stat.h"

// Fonction principale du jeu de devinette
void jeuDeDevinette(int max, int tentativesMax, const char* pseudo) {
    int nombreMystere = genererNombreAleatoire(max);
    int nombreEntre, coups = 0;

    printf("\nDevinez le nombre mystère entre 1 et %d\n", max);

    do {
        printf("Entrez un nombre : ");
        if (scanf("%d", &nombreEntre) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre entier.\n");
            while (getchar() != '\n'); // Vider le tampon d'entrée
            continue;
        }
        coups++;
        enregistrerTentative(nombreEntre, pseudo); // Enregistrer chaque tentative avec le pseudo

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

    calculerEcartType(pseudo); // Calculer l'écart-type des tentatives à la fin du jeu
}
