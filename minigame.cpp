#include <iostream>
#include <random>

void setLevel(int lvl, int &width, int &win, int &obstacle, int &obstacle1, int &obstacle2, int &coin, int &enemy, bool &enemyAlive, bool &coinCollected) {
    if (lvl == 1) {
        width = 35; //tu dlugosc mapy
        win = 34;
        obstacle = 5;
        obstacle1 = 9;
        obstacle2 = 14;
        coin = 8;
        enemy = 20;
    }
    else if (lvl == 2) {
        width = 35; //tu dlugosc mapy
        win = 34;
        obstacle = 18;
        obstacle1 = 15;
        obstacle2 = 6;
        coin = 20;
        enemy = 30;
    }
    enemyAlive = true;
    coinCollected = false;
}

void game() {
    int level = 1;
    int width, win, obstacle, obstacle1, obstacle2, coin, enemy;
    bool enemyAlive;
    bool coinCollected;
    int position = 0;
    char key;

    setLevel(level, width, win, obstacle, obstacle1, obstacle2, coin, enemy, enemyAlive, coinCollected);

    while (true) {
        std::cout << "\x1b[2J\x1b[H\n\n"; //czyszczenie terminala (tak wiem chore dziwne znaki ja tego nie pisalem)

        for (int i = 0; i < width; i++) {
            if (i == position) {
                std::cout << '%';
            }
            else if (i == win) {
                std::cout << 'P';
            }
            else if (i == obstacle) {
                std::cout << '^';
            }
            else if (i == obstacle2) {
                std::cout << '^';
            }
            else if (i == obstacle1) {
                std::cout << ' ';
            }
            else if (i == coin && !coinCollected) {
                std::cout << '$';
            }
            else if (i == enemy && enemyAlive) {
                std::cout << '@';
            }
            else {
                std::cout << '.';
            }
        }

        std::cout << "\nLevel: " << level << "\nposition: " << position;
        std::cout << "\nmoving -> a/d  jumping -> w  attack -> f  collect coin -> e  quit -> q\nCoin collected (" << coinCollected << "/1)\nYour move: ";

        std::cin >> key;

        if (key == 'd' && position < width - 1 && position + 1 != obstacle && position + 1 != obstacle2) {
            position++;
        }
        if (key == 'a' && position > 0 && position - 1 != obstacle && position - 1 != obstacle2) {
            position--;
        }
        if (key == 'q') {
            break;
        }
        if (position == win) {
            level++;
            if (level > 2) {
                std::cout << "\nYOU WON!\nCoin collected (" << coinCollected << "/1)\n";
                break;
            }
            setLevel(level, width, win, obstacle, obstacle1, obstacle2, coin, enemy, enemyAlive, coinCollected);
            position = 0;
        }
        if ((key == 'w' && position + 1 == obstacle && position + 2 < width) || (key == 'w' && position + 1 == obstacle1 && position + 2 < width) || (key == 'w' && position + 1 == obstacle2 && position + 2 < width)) {
            position += 2;
        }
        else if ((key == 'w' && position - 1 == obstacle && position - 2 >= 0) || (key == 'w' && position - 1 == obstacle1 && position - 2 >= 0) || (key == 'w' && position - 1 == obstacle2 && position - 2 >= 0)) {
            position -= 2;
        }
        if (key == 'd' && position == obstacle1) {
            position++;
            std::cout << "\nyou fell in hole, try again!\n";
            break;
        }
        if (key == 'a' && position == obstacle1) {
            position--;
            std::cout << "\nyou fell in hole, try again!\n";
            break;
        }
        if (position == coin && key == 'e' && !coinCollected) {
            coinCollected = true;
        }
        if ((enemy == position) || (enemy == position) && enemyAlive) {
            std::cout << "\nmonster killed you, try again\n";
            break;
        }

        if (key == 'f' && (enemy == position + 1) || (enemy == position) || (enemy == position - 1) && enemyAlive) {
            enemyAlive = false;
            std::cout << "\nmonster killed!\n";
            enemy += 50;
        }
        if (enemyAlive && enemy - 1 != position && enemy +1 != win) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> moveE(-1, 1);
            enemy += moveE(gen);
        }
        else if (enemy +1 == win) {
            enemy--;
        }
    }
}

int main() {
    std::cout << "\x1b[2J\x1b[H\n\n";
    char asdf;
    std::cout << R"(   _____   .__         .__        ____
  /     \  |__|  ____  |__|      / ___\ _____     _____    ____
 /  \ /  \ |  | /    \ |  |     / /_/  >\__  \   /     \ _/ __ \
/    Y    \|  ||   |  \|  |     \___  /  / __ \_|  Y Y  \\  ___/
\____|__  /|__||___|  /|__|    /_____/  (____  /|__|_|  / \___  >
        \/          \/                       \/       \/      \/
)";
    std::cout << "\nTo play a game type anything and click enter or q to quit: ";
    std::cin >> asdf;
    if (asdf == 'q') {
        return 0;
    }
    else {
        game();
    }
}
