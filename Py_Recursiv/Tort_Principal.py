from Tort_Func import *
from Generator_Straturi_Tort import *
from time import time as t  # Am importat functia time numind-o "t"

fisier_ajutor_bucatari = open("ajutor_bucatari.txt", "w")
platou_intial = "Platou Argint"
platou_final = "Platou Aur"
platou_ajutator = "Platou Bronz"

fisier_ajutor_bucatari.write("Acestea sunt mutarile care vor ajuta bucatarii sa mute tortul de "+str(nr_straturi_tort)+" straturi\n\n")

start = t()
muta_tortul(nr_straturi_tort, "Platou Argint", "Platou Aur", "Platou Bronz", fisier_ajutor_bucatari)
stop = t()
afisare_numar_pasi(fisier_ajutor_bucatari)
timp_executie = stop-start
fisier_ajutor_bucatari.write("\nExecutia a durat "+str(timp_executie)+" secunde")
print("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de "+str(nr_straturi_tort)+" straturi\n")

fisier_ajutor_bucatari.close()

# Procedura prin care am efectuat teste este urmatoarea:
# Intr-un vector am salvat straturile de tort pentru care urmeaza sa fie rulat programul, apoi l am rulat si am salvat
# Straturile de tort pot if citite in vector si dintr-un fisier
# rezultatele in cele 10 fisiere de test


# lista_teste = [1, 3, 6, 14, 15, 20, 21, 27, 30, 31]

# Lista de teste poate fi modificata manual din fisierul date_intrare.txt

# fisier_straturi = open("date_intrare.txt", "r")
# lista_teste = fisier_straturi.read().split()

#for i in range(1, 10):
     #nume_fisier_test = "Teste_Efectuate\\test"+str(i+1)+".txt"

     #fisier_test = open(nume_fisier_test, "w")
     #nr_straturi_tort = int(lista_teste[i])

     #platou_intial = "Platou Argint"
     #platou_final = "Platou Aur"
     #platou_ajutator = "Platou Bronz"

     #fisier_test.write("Acestea sunt mutarile care vor ajuta bucatarii sa mute tortul de " + str(nr_straturi_tort) + " straturi\n\n")

     #start = t()
     #muta_tortul(nr_straturi_tort, "Platou Argint", "Platou Aur", "Platou Bronz", fisier_test)
     #stop = t()
     #afisare_numar_pasi(fisier_test)
     #timp_executie = stop - start
     #fisier_test.write("\nExecutia a durat " + str(timp_executie) + " secunde")

     #print("S-au generat miscarile care vor ajuta bucatarii sa mute tortul de " + str(nr_straturi_tort) + " straturi\n")

     #fisier_test.close()
