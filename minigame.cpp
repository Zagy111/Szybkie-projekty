#include <iostream>
#include <random>

void game() {

    const int width = 35; //tu dlugosc mapy
    const int win = 34;
    const int obstacle = 5;
    const int obstacle1 = 15;
    const int coin = 8;
    int enemy = 20;
    bool enemyAlive = true;
    bool coinCollected = false;
    int position = 0; //pozycjaa gracza
    char key;


    while (true) {
        std::cout << "\x1b[2J\x1b[H\n\n"; //czyszczenie terminala (tak wiem chore dziwne znaki ja tego nie pisalem)

        for (int i = 0; i <width; i++) {

            if (i == position) {
                std::cout << '%';
            }
            else if (i == win) {
                std::cout << 'P';
            }
            else if (i == obstacle) {
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


            std::cout << "\n" << position;
            std::cout << "\nmoving -> a/d  jumping -> w  attack -> f  collect coin -> e  quit -> q\nCoin collected (" << coinCollected << "/1)\nYour move: ";


            std::cin >> key;
            
            if (key == 'd' && position < width - 1 && position +1 != obstacle) {
                position++;
            }
            if (key == 'a' && position > 0 && position - 1 != obstacle) {
                position--;
            }
            if (key == 'q') {
                break;
            }
            if (position == win) {
                std::cout << "\nYOU WON!\nCoin collected (" << coinCollected << "/1)\n";
                break;
            }
            if ((key == 'w' && position + 1 ==obstacle && position + 2 < width) || (key == 'w' && position + 1 ==obstacle1 && position + 2 < width)) {
                position += 2;
            }
            else if ((key == 'w' && position - 1 ==obstacle && position - 2 >=0) || (key == 'w' && position - 1 ==obstacle1 && position - 2 >=0)) {
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

            if (key == 'f' && (enemy == position +1) || (enemy == position) || (enemy == position -1) && enemyAlive){
                enemyAlive = false;
                std::cout << "\nmonster killed!\n";
                enemy += 50;
            }
            if (enemyAlive && enemy -1 != position){
                
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> moveE(-1,1);
                enemy += moveE(gen);
                
            }

            

}

}



int main() {
    //game();
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
    if (asdf == 'q'){
        return 0;
    }
    else{
        game();
    }
}