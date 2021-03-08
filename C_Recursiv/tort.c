#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tort.h"
#include <time.h>
#define limita_afisari 1000


//Functia prin care se vor salva (afisa) pasii prin care se muta recursiv tortul de pe platou initial pe cel final
//Am adaugat un contor, nr_mutarii, care va limita numarul de salvari in fisier si va numara si nr de pasi efectuati pentru mutarea straturilor
void muta_tortul(int numar_felii,char platou_initial[20],char platou_final[20],char platou_ajutator[],FILE *fila_output)
{
    if(numar_felii==1)
    {
        //In cazul in care se ajunge sa fie doar un element acesta se va muta pe platoul considerat sa fie final apoi se va inchide recursivitatea curenta
        numarul_mutarii++;
        if(numarul_mutarii<limita_afisari)           //Conditia care va limita numarul de afisari.
        {
            fprintf(fila_output,"Se muta stratul 1 al tortului de pe %s pe %s\n", platou_initial, platou_final);       //Am scris in fisierul deschis pasul
        }
        return ;
    }
    else
    {
        /*Se considera ca se vor muta recursiv toate celelate straturi ale tortului pe pozitia auxiliara in afara de ultimul strat al tortului pentru ca acesta
        sa fie mutat pe pozitia finala apoi aceste straturi urmand sa fie asezate peste stratul final(straturile aflandu-se pe cel ajutator) */
        muta_tortul(numar_felii-1, platou_initial,platou_ajutator,platou_final,fila_output);

        numarul_mutarii++;
        if(numarul_mutarii<limita_afisari)
        {
            fprintf(fila_output,"Se muta stratul %d al tortului de pe %s pe %s\n",numar_felii,platou_initial,platou_final);   //Am scris in fisierul deschis pasul
        }

        muta_tortul(numar_felii-1, platou_ajutator,platou_final,platou_initial,fila_output);
    }
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

    clock_t start, stop;
    float timp_executie;  //Variabila in care se va salva timpul de executie

    for (int i = 0; i < 10; i++)
    {
        numarul_mutarii = 0;
        sprintf(nume_fisier, "Teste_Efectuate\\test%d.txt", i+1 ); // scrie pe rand in sirul de caractere -nume_fisier- test1.txt, test2.txt etc pentru a putea fi accesat la scrierea in fisier

        fisier_test = fopen(nume_fisier, "w" ); // deschide fisierele test1, test2, ... in modul scriere
        int nr_straturi_tort = vector_teste[i] ; // Vom atribui variabilei nr_straturi_tort, o valoare din vectorul de teste corespunzatoare testului

        fprintf(fisier_test,"Acestea sunt miscarile care vor ajuta bucatarii sa mute tortul de %d straturi\n\n",nr_straturi_tort);

        start= clock();
        muta_tortul(nr_straturi_tort, "Platou argint", "Platou aur", "Platou bronz", fisier_test);
        stop = clock();
        timp_executie = (stop-start)/CLOCKS_PER_SEC;
        fprintf(fisier_test,".\n.\n.\nPentru a muta tortul va fi nevoie de %d pasi",numarul_mutarii);
        fprintf(fisier_test,"\nExecutia a duarat %.6f secunde",timp_executie);
        fclose(fisier_test);

        printf("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de %d straturi in %s.\n",nr_straturi_tort,nume_fisier);
    }
}

