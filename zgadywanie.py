import random

print("-=-=-=-=ZGADNIJ LICZBE-=-=-=-=")
print("~~~~~~~~~~~~(1-100)~~~~~~~~~~~")
print("poziom trudnosci:")
print("1 - Normalny (masz nieskonczone proby)")
print("2 - Trudny   (masz maksymalnie 7 prob)")
print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
tryb = input("Wybor (1/2): ")
tajna_liczba = random.randint(1, 100)
proby = 0
strzal = 0

while strzal != tajna_liczba:
    try:
        strzal = int(input("Podaj liczbe:"))
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
