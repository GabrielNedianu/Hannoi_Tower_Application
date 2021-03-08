limita_afisari = 1000  # Variabila ce limiteaza numarul de afisari


def scoate_ultimul_strat(platou):
    if len(platou) > 0:
        platou_strat_sus = platou.pop()
    else:
        platou_strat_sus = -2
    return platou_strat_sus


def muta_discurile_intre_2_platouri(platou_1, platou_2, platou_1_nume, platou_2_nume, fila_output):
# Se salveaza straturile superioare in doua variabile
    platou_1_strat_sus = scoate_ultimul_strat(platou_1)
    platou_2_strat_sus = scoate_ultimul_strat(platou_2)
# Daca primul platou este gol se va adauga primul strat de pe cel de al doilea deasupra
    if platou_1_strat_sus == -2:
        fila_output.write("Se muta stratul " + str(platou_2_strat_sus) + " al tortului din " + platou_2_nume + " pe " + platou_1_nume + "\n")
        platou_1.append(platou_2_strat_sus)
# Daca al doilea platou este gol se va adauga primul strat de pe primul platou deasupra
    elif platou_2_strat_sus == -2:
        fila_output.write("Se muta stratul " + str(platou_1_strat_sus) + " al tortului din " + platou_1_nume + " pe " + platou_2_nume + "\n")
        platou_2.append(platou_1_strat_sus)
# Daca ultimul strat de pe primul platou este mai mare se muta ultimul strat al celui de al doilea platou peste acesta
    elif platou_1_strat_sus > platou_2_strat_sus:
        fila_output.write("Se muta stratul " + str(platou_2_strat_sus) + " al tortului din " + platou_2_nume + " pe " + platou_1_nume + "\n")
        platou_1.append(platou_1_strat_sus)
        platou_1.append(platou_2_strat_sus)
# Daca ultimul strat de pe al doilea platou este mai mare se muta ultimul strat al primului platou peste acesta
    else:
        fila_output.write("Se muta stratul " + str(platou_1_strat_sus) + " al tortului din " + platou_1_nume + " pe " + platou_2_nume + "\n")
        platou_2.append(platou_2_strat_sus)
        platou_2.append(platou_1_strat_sus)

# Aceiasi functie doar ca nu mai salveaza mutarile

def muta_discurile_intre_2_platouri_fara_salvare(platou_1, platou_2, platou_1_nume, platou_2_nume, fila_output):
    platou_1_strat_sus = scoate_ultimul_strat(platou_1)
    platou_2_strat_sus = scoate_ultimul_strat(platou_2)
    if platou_1_strat_sus == -2:
        platou_1.append(platou_2_strat_sus)
    elif platou_2_strat_sus == -2:
        platou_2.append(platou_1_strat_sus)
    elif platou_1_strat_sus > platou_2_strat_sus:
        platou_1.append(platou_1_strat_sus)
        platou_1.append(platou_2_strat_sus)
    else:
        platou_2.append(platou_2_strat_sus)
        platou_2.append(platou_1_strat_sus)


def muta_tortul(nr_straturi_tort, platou_initial, platou_final, platou_ajutator, fila_output):
    platou_initial_nume = "Platou argint"
    platou_final_nume = "Platou aur"
    platou_ajutator_nume = "Platou bronz"
# Daca numarul de straturi este par, vom schimba intre ele platoul final si cel auxiliar
    if nr_straturi_tort % 2 == 0:
        temp = platou_final_nume
        platou_final_nume = platou_ajutator_nume
        platou_ajutator_nume = temp
# Se adauga pe platoul initial straturile tortului (de la cel mai mare la cel mai mic)
    i = nr_straturi_tort
    while i > 0:
        platou_initial.append(i)
        i = i - 1
    numarul_mutarii = 0  #Iteratorul folosit pentru a limita afisarile si a memora mutarile
# Incepe iteratia prin care sunt mutate straturile pe rand dupa regula si dupa miscarile disponibile

# Iteratia va rula pana cand unul dintre celelate doua platouri va fi plin(se intampla aceasta deoarece depinde daca
#  numarul de straturi este par se vor muta practic pe platoul ajutator ce a luat numele platoului final)

    while (len(platou_final) < nr_straturi_tort) & (len(platou_ajutator) < nr_straturi_tort):
        numarul_mutarii = numarul_mutarii + 1
        if(numarul_mutarii < limita_afisari):
            # Daca restul miscarii prin impartirea la 3 este 1 se va face o mutare intre platoul initial si cel final
            if numarul_mutarii % 3 == 1:
                muta_discurile_intre_2_platouri(platou_initial, platou_final, platou_initial_nume, platou_final_nume, fila_output)
            # Daca restul miscarii prin impartirea la 3 este 2 se va face o mutare intre platoul initial si cel ajutator
            elif numarul_mutarii % 3 == 2:
                muta_discurile_intre_2_platouri(platou_initial, platou_ajutator, platou_initial_nume, platou_ajutator_nume, fila_output)
            # Daca miscarea este divizibila cu 3 se va face o mutare intre platoul ajutator si cel final
            elif numarul_mutarii % 3 == 0:
                muta_discurile_intre_2_platouri(platou_ajutator, platou_final, platou_ajutator_nume, platou_final_nume, fila_output)
        else:
            if numarul_mutarii % 3 == 1:
                muta_discurile_intre_2_platouri_fara_salvare(platou_initial, platou_final, platou_initial_nume, platou_final_nume, fila_output)
            elif numarul_mutarii % 3 == 2:
                muta_discurile_intre_2_platouri_fara_salvare(platou_initial, platou_ajutator, platou_initial_nume, platou_ajutator_nume, fila_output)
            elif numarul_mutarii % 3 == 0:
                muta_discurile_intre_2_platouri_fara_salvare(platou_ajutator, platou_final, platou_ajutator_nume, platou_final_nume, fila_output)

    fila_output.write(".\n.\n.\nPentru a muta tortul va fi nevoie de "+str(numarul_mutarii)+" pasi")
