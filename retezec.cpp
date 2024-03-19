//
// Created by tomas on 16.03.2024.
//

#include "retezec.h"
#include <iostream>

void Retezec::vypis() {
    std::cout << text << std::endl;
}

void Retezec::nastavText(const char *novyText) {
    int newSize = 0;
    while (novyText[newSize] != '\0') {
        newSize++;
    }

    delete[] text;
    text = new char[newSize + 1];
    for (int i = 0; i < newSize; ++i) {
        text[i] = novyText[i];
    }
    text[newSize] = '\0';

    size = newSize;
}

int Retezec::getLenght() {
    int delka = 0;
    while (text[delka] != '\0') {
        delka++;
    }
    return delka;
}

char &Retezec::operator[](int index) {
    if (index >= 0 && index < size) {
        return text[index];
    }
    return text[size - 1];
}

Retezec &Retezec::operator=(const Retezec &other) {
    if (this != &other) {
        delete[] text;

        size = other.size;
        text = new char[size + 1];

        for (int i = 0; i < size; ++i) {
            text[i] = other.text[i];
        }
        text[size] = '\0';
    }
    return *this;
}

Retezec &Retezec::operator+=(const Retezec &other) {
    int newLength = size + other.size;
    char *newData = new char[newLength + 1];

    for (int i = 0; i < size; ++i) {
        newData[i] = text[i];
    }

    for (int i = 0; i < other.size; ++i) {
        newData[size + i] = other.text[i];
    }

    newData[newLength] = '\0';

    delete[] text;
    text = newData;
    size = newLength;

    return *this;
}

Retezec operator+(const Retezec &prvni, const Retezec &druhy) {
    Retezec result;
    result.size = prvni.size + druhy.size;
    result.text = new char[result.size + 1];
    for (size_t i = 0; i < prvni.size; ++i) {
        result.text[i] = prvni.text[i];
    }
    for (size_t i = 0; i < druhy.size; ++i) {
        result.text[prvni.size + i] = druhy.text[i];
    }
    result.text[result.size] = '\0';
    return result;
}

/*Retezec &Retezec::operator+(const Retezec &other) const {
    Retezec result; // Vytvoření nového Stringu

    result.size = size + other.size; // Nová délka řetězce

    result.text = new char[result.size + 1]; // Vytvoření nového pole pro spojený řetězec

    // Kopírování prvního řetězce
    for (int i = 0; i < size; ++i) {
        result.text[i] = text[i];
    }

    // Kopírování druhého řetězce
    for (int i = 0; i < other.size; ++i) {
        result.text[size + i] = other.text[i];
    }

    result.text[result.size] = '\0'; // Null-terminátor na konci nového pole

    return result; // Návrat vytvořeného řetězce
}
*/

