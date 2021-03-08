# Afisarile de mutari sunt limitate la 1000
limita_afisari = 1000

# Variabila in care se vor salva numarul mutarilor efectuate.
numarul_mutarii = 0

# Functia prin care se vor afisa pasii prin care se muta recursiv tortul de pe platou initial pe cel final
def muta_tortul(nr_felii, platou_initial, platou_final, platou_ajutator, fila_output):
    if nr_felii == 1:
        # In cazul in care se ajunge sa fie doar un element acesta se va muta pe platoul considerat sa fie final apoi se va inchide recursivitatea curenta
        globals()['numarul_mutarii'] += 1
        if numarul_mutarii < limita_afisari:
            fila_output.write("Se muta stratul 1 al tortului din "+platou_initial+" in "+platou_final+"\n")  #Am scris in fisierul ajutator pasul
        return
    else:
# Se considera ca se vor muta recursiv toate celelate straturi ale tortului pe platoul ajutator, in afara de ultimul strat al tortului pentru ca acesta
#   sa fie mutat pe platoul final, apoi aceste straturi urmand sa fie asezate peste stratul final aflat pe platoul ajutator)
        muta_tortul(nr_felii-1, platou_initial, platou_ajutator, platou_final, fila_output)

        globals()['numarul_mutarii'] += 1
        if numarul_mutarii < limita_afisari:
            fila_output.write("Se muta stratul "+str(nr_felii)+" al tortului din "+platou_initial+" pe "+platou_final+"\n")  #Am scris in fisier pasul

        muta_tortul(nr_felii-1, platou_ajutator, platou_final, platou_initial, fila_output)


# Am implementat o functie care sa permita afisarea numarului de pasi
def afisare_numar_pasi(fila_output):
    fila_output.write(".\n.\n.\nPentru a muta tortul va fi nevoie de " + str(numarul_mutarii) + " pasi")
    globals()['numarul_mutarii'] = 0

# Dupa ce este afisat numarul de pasi pentru recursivitatea anterioara, acesta este resetat la 0
