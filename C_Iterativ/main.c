#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generator_nr_straturi.h"
#include "tort.h"


int main()
{
    clock_t start, stop;            //Am creat start si stop pentru a masura timpul executiei

    genereaza_straturi_tort();      //Generare aleatorie numar de straturi

    FILE *fisier_ajutor_bucatari=fopen("ajutor_bucatari.txt","w");        //Am deschis fisierul unde se vor salva pasii ce ii vor ajuta pe bucatari

    fprintf(fisier_ajutor_bucatari,"Acestea sunt miscarile care vor ajuta bucatarii sa mute tortul de %d straturi\n\n",nr_straturi_tort);

    //Se vor crea 3 stive(numite platou) de dimensiunea nr_straturi_tort(care va fi generata random) care vor salva straturile tortului aflate respectiv pe ele
    struct Platou *platou_initial, *platou_final, *platou_ajutator;
    platou_initial = creaza_platou(nr_straturi_tort, "Platou argint");
    platou_ajutator = creaza_platou(nr_straturi_tort, "Platou bronz");
    platou_final = creaza_platou(nr_straturi_tort, "Platou aur");

    start= clock();
    muta_tortul(nr_straturi_tort, platou_initial, platou_final, platou_ajutator, fisier_ajutor_bucatari);
    stop = clock();
    float timp_executie = (stop-start)/CLOCKS_PER_SEC;
    fprintf(fisier_ajutor_bucatari, "\nExecutia a durat %.6f secunde", timp_executie);
    fclose(fisier_ajutor_bucatari);

    printf("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de %d straturi in fisier_ajutor_bucatari.\n", nr_straturi_tort);   //Mesajul final care afiseaza terminarea executiei programului

    //test();     // Functia ce va efectuea testele ( este comentata deoarece a fost deja folosita)

    return 0;
}
