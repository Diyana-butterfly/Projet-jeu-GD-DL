#include <stdlib.h>
#include <time.h>
#include "random.h"

// Génère un nombre aléatoire entre 1 et max
int genererNombreAleatoire(int max){
    srand(time(NULL));
    return rand() % max + 1;
}
