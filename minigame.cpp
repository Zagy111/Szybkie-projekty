#include <iostream>

void game() {

    const int width = 20; //tu dlugosc mapy
    const int win = 19;
    const int obstacle = 5;
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
            else {
                std::cout << '.';
            }
        }


            std::cout << "\n###################\n" << position;
            std::cout << "\nmoving -> a/d  jumping -> w  quit -> q\nYour move: ";


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
                std::cout << "\nYOU WON!\n";
                break;
            }
            if (key == 'w' && position + 1 ==obstacle && position + 2 < width) {
                position += 2;
            }
            else if (key == 'w' && position - 1 ==obstacle && position - 2 >=0) {
                position -= 2;
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