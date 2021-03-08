from Tort_Functii import *
from Generator_Nr_Straturi import *
from time import time as t  # Am importat functia time numind-o "t"

fisier_ajutor_bucatari = open("ajutor_bucatari.txt", "w")

platou_initial = []
platou_final = []
platou_ajutator = []


fisier_ajutor_bucatari.write("Acestea sunt mutarile care vor ajuta bucatarii sa mute tortul de "+str(nr_straturi_tort)+" straturi\n\n")
start = t()
muta_tortul(nr_straturi_tort, platou_initial, platou_final, platou_ajutator, fisier_ajutor_bucatari)
stop = t()
timp_executie = stop-start
fisier_ajutor_bucatari.write("\nExecutia a durat "+str(timp_executie)+" secunde")

fisier_ajutor_bucatari.close()
print("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de "+str(nr_straturi_tort)+" straturi\n")


#lista_teste = [1, 3, 6, 14, 15, 20, 21, 27, 30, 31]

# Lista de teste poate fi modificata manual din fisierul date_intrare.txt

# fisier_straturi = open("date_intrare.txt", "r")
# lista_teste = fisier_straturi.read().split()


#for i in range(1, 10):
     #nume_fisier_test = "Teste_Efectuate\\test"+str(i+1)+".txt"
     #fisier_test = open(nume_fisier_test, "w")
     #nr_straturi_tort = lista_teste[i]
     #platou_initial = []
     #platou_final = []
     #platou_ajutator = []

     #fisier_test.write("Acestea sunt mutarile care vor ajuta bucatarii sa mute tortul de " + str(nr_straturi_tort) + " straturi\n\n")
     #start = t()
     #muta_tortul(nr_straturi_tort, platou_initial, platou_final, platou_ajutator, fisier_test)
     #stop = t()
     #timp_executie = stop - start
     #fisier_test.write("\nExecutia a durat " + str(timp_executie) + " secunde")

     #fisier_test.close()
     #print("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de " + str(nr_straturi_tort) + " straturi\n")
