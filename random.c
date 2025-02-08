#include <stdlib.h>
#include <time.h>
#include "random.h"

int genererNombreAleatoire(int max) {
    srand(time(NULL));
    return rand() % max + 1;
}
