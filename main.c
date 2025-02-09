/**********************************************************************
*Auteur         : GANDA & DAKEY
*Parcours       : EPL Génie Logiciel S3
*Années         : 2024-2025
*Description    : Programme de jeu de devinette
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "random.h"
#include "jeu.h"
#include "difficulte.h"
#include "pseudo.h"
#include "stat.h"

int main() {
    setlocale(LC_CTYPE, "");
    printf("\n\n\t\t\t\t\t=============================\n");
    printf("\t\t\t\t\t|  BIENVENUE SUR NOTRE JEU  |\n");
    printf("\t\t\t\t\t|        DE DEVINETTE       |\n");
    printf("\t\t\t\t\t=============================\n\n");

    char pseudo[100];
    char motDePasse[100];

    while (1) {
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("Entrez votre pseudo : ");
        // Demande du pseudo
        scanf("%99s", pseudo);

        if (verifierPseudoEtMotDePasse(pseudo, motDePasse) == 0) {
            // Demande du mot de passe pour un nouveau pseudo
            printf("Entrez votre mot de passe : ");
            scanf("%99s", motDePasse);

            if (enregistrerPseudo(pseudo, motDePasse)) {
                printf("\nInscription réussie pour %s.\n", pseudo);
                break;
            } else {
                printf("\nLe pseudo existe déjà. Veuillez en entrer un autre.\n");
            }
        } else {
            printf("\nConnexion réussie !\n");
            break;
        }
        printf("-----------------------------------------------------------------------------------------------------------\n");
    }

    srand(time(NULL)); // Initialisation de la graine aléatoire

    int max = 0, tentativesMax = 0;
    char decision[4];

      do {
        printf("-------------------------------------------------");
        printf("\n1. Jouer\n2. Voir les statistiques\n3. Quitter\n");
        printf("Votre choix : ");
        scanf("%3s", decision);
        printf("-------------------------------------------------\n");

        if (strcmp(decision, "1") == 0) {
            choisirNiveau(&max, &tentativesMax); // Choix du niveau de difficulté
            jeuDeDevinette(max, tentativesMax, pseudo); // Lancer le jeu de devinette avec le pseudo du joueur
        } else if (strcmp(decision, "2") == 0) {
            consulterTentatives(pseudo); // Consulter les tentatives et calculer l'écart-type pour le joueur
        } else if (strcmp(decision, "3") == 0) {
            printf("\nMerci d'avoir joué !\n");
            break;
        } else {
            printf("\nChoix invalide. Veuillez entrer 1, 2 ou 3.\n");
        }
    } while (1);




    printf("\nRetour au menu principal.\n");
    return 0;
}
