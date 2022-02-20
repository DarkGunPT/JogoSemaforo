//
// TP Programação - Jogo do Semáforo - Realizado por Nuno Gabriel Tavares Honório a2019126457
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

void initRandom(){
    srand(time(NULL));
}

int intUniformRnd(int a, int b){
    return a + rand()%(b-a+1);
}

