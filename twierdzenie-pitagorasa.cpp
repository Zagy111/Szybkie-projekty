#include <iostream>
#include <cmath>

int main(){
    double a;
    double b;
    double c;
    std::cout << "TWIERDZENIE PITAGORASA\n";
    std::cout << "  |\\\n  | \\\n  |  \\   c\na |   \\\n  |    \\\n  |     \\\n  -------\n     b\n\n";
    std::cout << "Podaj a: ";
    std::cin >> a;
    std::cout << "Podaj b: ";
    std::cin >> b;
    a = pow(a,2);
    b = pow(b,2);
    c = sqrt(a + b);
    std::cout << "\n-------------\nc to " << c << "\n-------------\n";
    
    
}