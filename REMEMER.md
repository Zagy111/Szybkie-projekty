# Do zapamietania
jezeli chcesz zeby byl twoj input w stringu z spacją zrób to:
```cpp
#include <iostream>

int main() {
    std::string x;
    std::cout << "imie: ";
    std::getline(std::cin >> std::ws, x);
    std::cout << x << '\n';


    return 0;
}
```
cały ```std::getline(std::cin >> std::ws, x);``` powoduje to ze wezmie pod uwage wszystko co napiszesz wraz z znakami białymi


jezeli masz zadanie zeby wypisac dla kazdego znaku ascii: 
```cpp
#include <iostream>

int main() {
    std::string znki;
    std::cout << "podaj znaki: ";
    std::cin >> znki;
    for (int i = 0; i < znki.length(); i++) {
    std::cout << znki[i] << " " << (int)znki[i] << std::endl;


    return 0;
}
```