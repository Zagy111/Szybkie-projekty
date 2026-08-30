import random
import os

def latwizna():
    tajna_liczba = random.randint(1, 100)
    proby = 0
    strzal = 0

    while strzal != tajna_liczba:
        try:
           strzal = int(input("Podaj liczbe: "))
        except ValueError:
           print("ale ziomek my zgadujemy liczby")
           continue
        proby = proby + 1
        if strzal == 67:
            print("haha 67")
        if strzal < tajna_liczba:
            print("Wyzej!")
        elif strzal > tajna_liczba:
           print("Nizej!")
        else:
           print(f"Brawo wygrales! miales {proby} prob!")

def trudny():
    tajna_liczba = random.randint(1, 100)
    proby = 0
    strzal = 0
    max_prob = 7
    while strzal !=tajna_liczba and max_prob > proby:
        try:
            strzal = int(input("Podaj liczbe: "))
        except:
            print("ale ziomek my zgadujemy liczby")
            continue
        proby = proby + 1
        if strzal == 67:
            print("haha 67")
        if strzal < tajna_liczba:
            print("Wyżej!")
        elif strzal > tajna_liczba:
            print("Niżej")
    if strzal == tajna_liczba:
        print(f"Brawo wygrales! miales {proby}/7 prob!")
    else:
        print("Przegrałeś przeiez było mowione ze trudne")



#menu
os.system('cls' if os.name == 'nt' else 'clear')
while True:
    print("-=-=-=-=ZGADNIJ LICZBE-=-=-=-=")
    print("~~~~~~~~~~~~(1-100)~~~~~~~~~~~")
    print("poziom trudnosci:")
    print("1 - Normalny (masz nieskonczone proby)")
    print("2 - Trudny   (masz maksymalnie 7 prob)")
    print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    tryb = input("Wybor (1/2): ")
    if tryb == "1":
        os.system('cls' if os.name == 'nt' else 'clear')
        latwizna()
    elif tryb == "2":
        os.system('cls' if os.name == 'nt' else 'clear')
        trudny()
    else:
        os.system('cls' if os.name == 'nt' else 'clear')
        print("wybierz 1 albo 2")