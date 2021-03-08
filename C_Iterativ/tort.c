#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tort.h"
#define limita_afisari 1000

struct Platou* creaza_platou(unsigned nr_straturi_maxime, char *Nume_Platou)  //Functia prin care se creaza o stiva(numita platou) ce va memora feliile de tort aflate pe ea
{
    struct Platou* Platou =(struct Platou*) malloc(sizeof(struct Platou));    //Structura platou va memora si numele fiecarui platou
    Platou -> nr_straturi_maxime = nr_straturi_maxime;
    Platou -> nume =(char*) malloc(20 * sizeof(char));
    Platou -> nume = Nume_Platou;
    Platou -> top = -1;                                                           //Cand "top" este egal cu -1 platoul nu are nici un strat pe el
    Platou -> vector =(int*) malloc(Platou -> nr_straturi_maxime * sizeof(int)); //Se creaza vectorul in care se vor stoca straturile tortului
    return Platou;
}

int este_plin(struct Platou* Platou)     //Se creaza functia prin care verificam daca platoul este plin(conditie verificata cand "top" este egal cu straturile maxime ce pot fi puse)
{
    return (Platou->top == Platou->nr_straturi_maxime - 1);
}

int nu_sunt_straturi(struct Platou* Platou)  //Platoul nu are nici un strat pe el cand "top" este egal cu -1
{
    return (Platou->top ==-1);
}

void adauga(struct Platou *Platou, int strat)  //Functia prin care se adauga un strat nou pe Platou
{                                             //Valoarea "top" este crescuta cu 1
    if (este_plin(Platou))
        return;
    Platou -> vector[++Platou -> top] = strat;
}

int scoate_stratul(struct Platou* Platou)      //Functie prin care se scoate ultimul strat pus pe un Platou
{                                             //Valoarea "top" se reduce cu 1
    if (nu_sunt_straturi(Platou))              //Daca nu sunt straturi se va returna valoarea "-2"
        return -2;
    return Platou -> vector[Platou -> top--];
}

void muta_disc_salvare(int strat, char de_pe_platoul[20], char pe_platoul[20],FILE *file)      //Functie prin care se va salva miscarea in fisier
{
    fprintf(file,"Se muta startul %d al tortului de pe %s pe %s\n",strat, de_pe_platoul, pe_platoul);
}

void creaza_tortul(struct Platou *platou,int nr_straturi)   //Se adauga pe un platou straturile tortului (de la cel mai mare la cel mai mic)
{
    int i;
    for (i = nr_straturi; i >= 1; i--)
    {
        adauga(platou, i);
    }
}

void muta_straturile_intre_2_platouri(struct Platou *platou_1, struct Platou *platou_2, FILE *file)
{                                                                           //Functie prin care se va muta unul dintre straturi pe celalat platou(oricum am incerca sa mutam doua straturi intre 2 platouri este posibila doar o miscare)
    int platou_1_strat_sus = scoate_stratul(platou_1);
    int platou_2_strat_sus = scoate_stratul(platou_2);              //Straturile de sus se vor salva in doua variabile locale

    if (platou_1_strat_sus == -2)                                //Cand platoul 1 este gol se va adauga pe acesta stratul superior de pe platoul 2
    {
        adauga(platou_1, platou_2_strat_sus);
        muta_disc_salvare(platou_2_strat_sus, platou_2->nume, platou_1->nume, file);
    }

    else if (platou_2_strat_sus == -2  )                          //Cand platoul 2 este gol se va adauga pe acesta stratul superior de pe platoul 1
    {
        adauga(platou_2, platou_1_strat_sus);
        muta_disc_salvare(platou_1_strat_sus, platou_1->nume, platou_2->nume, file);

    }
    else if (platou_1_strat_sus > platou_2_strat_sus)           //Cand stratul superior de pe platoul 1 este mai mare decat cel de pe platoul 2 se va adauga stratul superior de pe platoul 2 peste stratul superior de pe platoul 1
    {                                                          //(dar mai intai se va adauga stratul superior al platoului 1 la loc)
        adauga(platou_1, platou_1_strat_sus);
        adauga(platou_1, platou_2_strat_sus);
        muta_disc_salvare(platou_2_strat_sus, platou_2->nume, platou_1->nume, file);
    }
    else                                                        //Cand stratul superior de pe platoul 2 este mai mare decat cel de pe platoul 1 se va adauga stratul superior de pe platoul 1 peste stratul superior de pe platoul 2
    {                                                          //(dar mai intai se va adauga stratul superior de pe platoul 2 la loc)
        adauga(platou_2, platou_2_strat_sus);
        adauga(platou_2, platou_1_strat_sus);
        muta_disc_salvare(platou_1_strat_sus, platou_1->nume, platou_2->nume, file);
    }
}

void muta_straturile_intre_2_platouri_fara_afisare(struct Platou *platou_1, struct Platou *platou_2)    //Aceeasi functie ca mai sus, doar ca nu se mai salveaza mutarile pentru a economisi spatiu.
{
    int platou_1_strat_sus = scoate_stratul(platou_1);
    int platou_2_strat_sus = scoate_stratul(platou_2);

    if (platou_1_strat_sus == -2)
    {
        adauga(platou_1, platou_2_strat_sus);
    }

    else if (platou_2_strat_sus == -2  )
    {
        adauga(platou_2, platou_1_strat_sus);
    }
    else if (platou_1_strat_sus > platou_2_strat_sus)
    {
        adauga(platou_1, platou_1_strat_sus);
        adauga(platou_1, platou_2_strat_sus);
    }
    else
    {
        adauga(platou_2, platou_2_strat_sus);
        adauga(platou_2, platou_1_strat_sus);
    }
}


//Functia principala prin care se muta tortul de pe platoul initial pe cel final
void muta_tortul(int nr_straturi_tort, struct Platou *platou_initial, struct Platou *platou_final,  struct Platou *platou_ajutator, FILE *file)
{
    unsigned int numarul_mutarii=0;    //Aceasta variabila va numara cate mutari se vor face de-a lunugul programului in scopul mutarii tortului

    if (nr_straturi_tort % 2 == 0)       //Daca numarul de straturi este par, vom schimba intre ele platoul final si cel auxiliar
    {
        char temp[20] = "Platou aur";
        platou_final->nume = platou_ajutator->nume;
        platou_ajutator->nume = temp;
    }

    creaza_tortul(platou_initial,nr_straturi_tort);   //Se adauga pe platoul initial straturile tortului (de la cel mai mare la cel mai mic)

    while ((este_plin(platou_final) != 1) && (este_plin(platou_ajutator) != 1))    //Incepe iteratia prin care sunt mutate straturile pe rand dupa regula si dupa miscarile disponibile pana cand platoul final se va umple
    {
        numarul_mutarii++;
        if(numarul_mutarii < limita_afisari)       //Am adaugat conditia care va limita numarul de salvari al pasilor in fisierul final deoare acest fisier ar fi prea mare
        {
            if (numarul_mutarii % 3 == 1)          //Daca restul miscarii prin impartirea la 3 este 1 se va face o mutare intre platoul initial si cel final
                muta_straturile_intre_2_platouri(platou_initial, platou_final, file);

            else if (numarul_mutarii % 3 == 2)     //Daca restul miscarii prin impartirea la 3 este 2 se va face o mutare intre platoul initial si cel ajutator
                muta_straturile_intre_2_platouri(platou_initial, platou_ajutator, file);

            else if (numarul_mutarii % 3 == 0)     //Daca miscarea este divizibila cu 3 se va face o mutare intre platoul ajutator si cel final
                muta_straturile_intre_2_platouri(platou_ajutator, platou_final, file);
        }
        else
        {
            if (numarul_mutarii % 3 == 1)
                muta_straturile_intre_2_platouri_fara_afisare(platou_initial, platou_final);

            else if (numarul_mutarii % 3 == 2)
                muta_straturile_intre_2_platouri_fara_afisare(platou_initial, platou_ajutator);

            else
                muta_straturile_intre_2_platouri_fara_afisare(platou_ajutator, platou_final);
        }
    }

        fprintf(file,".\n.\n.\nPentru a muta tortul va fi nevoie de %d pasi",numarul_mutarii);                 //Vom afisa la final cati pasi vor trebui facuti

}

void test()
{
    unsigned vector_teste[10] = {1,3,6,14,15,20,21,27,30,31} ;    //Aici am salvat numarul de straturi ce vor fi folosite pentru efectuarea testului

    /*FILE *date_intrare;
    date_intrare = fopen("date_intrare.txt", "r");
    for(int i = 0; i < 10; i++)
    {
        fscanf(date_intrare, "%d", &vector_teste[i]);    //Aceasta parte poate fi folosita daca dorim sa adaugam anumite valori pentru teste dintr-un fisier anume.
    }
    */

    FILE *fisier_test ;   //Se deschide pointer la fisierul in care se vor salva rezultatele testelor
    char nume_fisier[40];  // Am initializat un vector de caractere in care se vor salva,pe rand, numele fisierelor de test

    struct Platou *platou_initial, *platou_final, *platou_ajutator;
    clock_t start,stop;
    float timp_executie; int nr_straturi_tort;
    for(int i = 0; i < 10; i++)
    {
        sprintf(nume_fisier, "Teste_Efectuate\\test%d.txt", i+1 ); // scrie pe rand in sirul de caractere -nume_fisier- test1.txt, test2.txt etc pentru a putea fi accesat la scrierea in fisier

        fisier_test = fopen(nume_fisier, "w" ); // deschide fisierele test1, test2, ... in modul scriere
        nr_straturi_tort = vector_teste[i] ; // Vom atribui variabilei nr_straturi_tort, o valoare din vectorul de teste corespunzatoare testului

        fprintf(fisier_test,"Acestea sunt miscarile care vor ajuta bucatarii sa mute tortul de %d straturi\n\n",nr_straturi_tort);

        //Se vor reinitializa cele 3 stive(numite platou) de dimensiunea nr_straturi_tort care vor salva straturile tortului aflate respectiv pe ele
        platou_initial = creaza_platou(nr_straturi_tort, "Platou argint");
        platou_ajutator = creaza_platou(nr_straturi_tort, "Platou bronz");
        platou_final = creaza_platou(nr_straturi_tort, "Platou aur");

        start= clock();
        muta_tortul(nr_straturi_tort, platou_initial, platou_final, platou_ajutator,fisier_test);
        stop = clock();
        timp_executie = (stop-start)/CLOCKS_PER_SEC;
        fprintf(fisier_test,"\nExecutia a duarat %.6f secunde",timp_executie);
        fclose(fisier_test);

        printf("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de %d straturi in %s.\n",nr_straturi_tort,nume_fisier);
    }
}
