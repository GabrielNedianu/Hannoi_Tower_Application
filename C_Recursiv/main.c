#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generator_nr_straturi.h"
#include "tort.h"
#include <time.h>

int main()
{
    clock_t start, stop;  //Am initializat start si stop pentru a numara pasii pentru executia programului principal

    //Se genereaza aleatoriu numarul de straturi ale tortului ce vor fi mutate
    genereaza_straturi_tort();

    //Am deschis fisierul unde se vor salva pasii ce ii vor ajuta pe bucatari si am scris in el primul mesaj
    FILE *fisier_ajutor_bucatari=fopen("ajutor_bucatari.txt","w");
    fprintf(fisier_ajutor_bucatari,"Acestea sunt miscarile care vor ajuta bucatarii sa mute tortul de %d straturi\n\n", nr_straturi_tort);

    start = clock();
    muta_tortul(nr_straturi_tort, "Platou argint", "Platou aur", "Platou bronz", fisier_ajutor_bucatari);   //Functia principala este executata
    stop =clock();
    fprintf(fisier_ajutor_bucatari,".\n.\n.\nPentru a muta tortul va fi nevoie de %d pasi", numarul_mutarii);  //Vom afisa la final cate mutari vor trebui facute
    float timp_executie = (stop-start)/CLOCKS_PER_SEC;
    fprintf(fisier_ajutor_bucatari, "\nExecutia a durat %.6f secunde", timp_executie);  //Mesajul ce va salva timpul executiei programului
    fclose(fisier_ajutor_bucatari);

    printf("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de %d straturi in fisier_ajutor_bucatari.\n",nr_straturi_tort);  //Mesajul din consola ce arata terminarea salvarii in fisier a pasilor


    //test();   // Functia ce va efectuea testele ( este comentata deoarece a fost deja folosita)

    return 0;
}

