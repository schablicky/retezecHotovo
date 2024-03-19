//
// Created by tomas on 16.03.2024.
//

#ifndef PROVERKAOOP_RETEZEC_H
#define PROVERKAOOP_RETEZEC_H

class Retezec {
private:
    char* text;
    int size;

public:
    Retezec() {
        text = new char[1];
        text[0] = '\0';
    }

    Retezec(const Retezec &other) {
        size = other.size;
        text = new char[size+1];
        for (int i = 0; i < size; i++) {
            text[i] = other.text[i];
        }
        text[size] = '\0';
    }

    Retezec(const char *input) {
        size = 0;
        while(input[size] != '\0') {
            size++;
        }
        text = new char[size+1];
        for (int i = 0; i < size; i++) {
            text[i] = input[i];
        }
        text[size] = '\0';

    }

    ~Retezec() {
        delete[] text;
    }
    void vypis();
    void nastavText(const char* novyText);
    int getLenght();
    char& operator[](int index);
    Retezec& operator=(const Retezec &other);
    Retezec& operator+=(const Retezec &other);
    friend Retezec operator+(const Retezec&, const Retezec&);
};



#endif //PROVERKAOOP_RETEZEC_H
