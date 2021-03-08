#ifndef TORT_H_INCLUDED
#define TORT_H_INCLUDED

struct Platou                               //Se creaza stiva(numita platou) in care se vor salva straturile existente pe ea/el
{                                          //Capacitatea maxima a acesteia va fi nr_straturi_maxime
    unsigned nr_straturi_maxime;            //Am implementat stiva cu ajutorul unui vector deoarece numarul maxim de straturi este cunoscut si relativ mic
    char *nume;
    int top;
    int *vector;
};

struct Platou* creaza_platou(unsigned nr_straturi_maxime, char *Nume_Platou);
int este_plin(struct Platou* Platou);
int nu_sunt_straturi(struct Platou* Platou);
void adauga(struct Platou *Platou, int strat);
int scoate_stratul(struct Platou* Platou);
void muta_disc_afisare(int strat, char de_pe_platoul[20], char pe_platoul[20]);
void muta_disc_salvare(int strat, char de_pe_platoul[20], char pe_platoul[20], FILE *file);
void creaza_tortul(struct Platou *platou,int nr_straturi) ;
void muta_discurile_intre_2_platouri(struct Platou *platou_1, struct Platou *platou_2, FILE *file);
void muta_straturile_intre_2_platouri_fara_afisare(struct Platou *platou_1, struct Platou *platou_2);
void muta_tortul(int nr_straturi_tort, struct Platou *platou_initial, struct Platou *platou_final,  struct Platou *platou_ajutator, FILE *file);

void test();


#endif
