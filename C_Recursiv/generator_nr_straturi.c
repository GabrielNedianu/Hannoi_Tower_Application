#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator_nr_straturi.h"

void genereaza_straturi_tort()
    {
     srand(time(0)) ;
     nr_straturi_tort=rand()%31+1 ;
     return;
    }
