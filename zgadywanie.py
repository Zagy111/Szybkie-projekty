import random

print("-=-=-=-=ZGADNIJ LICZBE-=-=-=-=")
print("~~~~~~~~~~~~(1-100)~~~~~~~~~~~")
tajna_liczba = random.randint(1, 100)
proby = 0
strzal = 0

while strzal != tajna_liczba:
    strzal = int(input("Podaj liczbe:"))
    proby = proby + 1
    if strzal == 67:
        print("haha 67")
    if strzal < tajna_liczba:
        print("Wyzej!")
    elif strzal > tajna_liczba:
        print("Nizej!")
    else:
        print(f"Brawo wygrales! miales {proby} prob!")
