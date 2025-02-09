#include <stdio.h>
#include "random.h"
#include "jeu.h"
#include "stat.h"

// Fonction principale du jeu de devinette
void jeuDeDevinette(int max, int tentativesMax, const char* pseudo) {
    int nombreMystere = genererNombreAleatoire(max);
    int nombreEntre, coups = 0;

    printf("\nDevinez le nombre myst�re entre 1 et %d\n", max);

    do {
        printf("Entrez un nombre : ");
        if (scanf("%d", &nombreEntre) != 1) {
            printf("Entr�e invalide. Veuillez entrer un nombre entier.\n");
            while (getchar() != '\n'); // Vider le tampon d'entr�e
            continue;
        }
        coups++;
        enregistrerTentative(nombreEntre, pseudo); // Enregistrer chaque tentative avec le pseudo

        if (nombreEntre < nombreMystere) {
            printf("C'est plus !\n");
        } else if (nombreEntre > nombreMystere) {
            printf("C'est moins !\n");
        } else {
            printf("Bravo, vous avez trouv� le nombre myst�re en %d coups !\n", coups);
        }

        if (coups >= tentativesMax) {
            printf("D�sol�, vous avez atteint le nombre maximum de tentatives.\n");
            break;
        }
    } while (nombreEntre != nombreMystere);

    calculerEcartType(pseudo); // Calculer l'�cart-type des tentatives �la�fin�du�jeu
}
