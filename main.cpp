#include <iostream>
#include "retezec.h"

int main() {
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    const char *str3 = "test";

    Retezec test(str3);
    Retezec test2(test);
    test2.vypis(); // Výstup: test

    Retezec uprava("Uprava");
    uprava.vypis();
    uprava.nastavText("Upraveno");
    uprava.vypis();

    // Vytvoření objektů řetězce
    Retezec s1(str1);
    Retezec s2(str2);

    // Použití přetíženého operátoru +=
    std::cout << "Test operator +=:" << std::endl;
    s1 += s2;
    s1.vypis(); // Výstup: Hello, world!

    // Použití přetíženého operátoru +
    std::cout << "\nTest operator +:" << std::endl;
    Retezec s3 = s1 + s2;
    s3.vypis(); // Výstup: Hello, world!world!

    // Přetížený operátor =
    std::cout << "\nTest operator =:" << std::endl;
    Retezec s4 = "Hello";
    Retezec s5 = "world";
    std::cout << "Before assignment:" << std::endl;
    s4.vypis(); // Výstup: Hello
    s5.vypis(); // Výstup: world
    s4 = s5;
    std::cout << "After assignment:" << std::endl;
    s4.vypis(); // Výstup: world
    s5.vypis(); // Výstup: world

    // Přetížený operátor []
    std::cout << "\nTest operator []:" << std::endl;
    Retezec s6 = "Hello";
    std::cout << "Original string: ";
    s6.vypis(); // Výstup: Hello
    std::cout << "First character: " << s6[0] << std::endl; // Výstup: H
    std::cout << "Second character: " << s6[1] << std::endl; // Výstup: e

    return 0;
}
