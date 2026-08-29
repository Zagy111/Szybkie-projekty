import random
import string

print("GENERATOR HASEL")
length = int(input("(1/3) Dlugosc hasla:"))
chce_cyfry = input("(2/3) Chcesz cyfry (t/n):")
chce_specjalne = input("(3/3) chcesz znaki specjalne (t/n):")

znaki = string.ascii_letters

if chce_cyfry == "t":
    znaki = znaki + string.digits

if chce_specjalne == "t":
    znaki = znaki + string.punctuation

haslo = ""
for i in range(length):
    random_znak = random.choice(znaki)
    haslo = haslo + random_znak

print("====haslo====")
print(haslo)
print("=============")