#include <stdlib.h>
#include <time.h>
#include "random.h"

// G�n�re un nombre al�atoire entre 1 et max
int genererNombreAleatoire(int max){
    srand(time(NULL));
    return rand() % max + 1;
}
