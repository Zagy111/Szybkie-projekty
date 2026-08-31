import os
import random
import time

MOVES = {1: "rock", 2: "scissors", 3:"paper"}

while True:
    os.system('cls' if os.name == 'nt' else 'clear')
    print("ROCK PAPER SCISSORS")
    print("-------------------")
    print("|      choose:    |")
    print("|    1. rock      |")
    print("|    2. scissors  |")
    print("|    3. paper     |")
    print("-------------------")

    think = "your opponent is thinking"
    choice = input("your choice (1/2/3): ")
    
    if not choice.isdigit() or int(choice) not in [1, 2, 3]:
        print("invalid choice!")
        time.sleep(1.5)
        continue
    x = int(choice)

    i = 0
    thinking = random.randint(0, 3)
    while i <= thinking:
        os.system('cls' if os.name == 'nt' else 'clear')
        think += "."
        print(think)
        time.sleep(0.5)
        i += 1
    os.system('cls' if os.name == 'nt' else 'clear')
    randomChoice = random.randint(1, 3)

    print(f"you: {MOVES[x]}")
    print(f"opponent: {MOVES[randomChoice]}")
    if x == randomChoice:
        print("Draw!")
    elif (x == 1 and randomChoice == 2) or (x == 2 and randomChoice == 3) or (x == 3 and randomChoice == 1):
        print("You won!")
    else:
        print("You lost!")
    print("========================")
    print("Next battle in 3 seconds")
    time.sleep(3)


