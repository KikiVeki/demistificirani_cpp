//
// Created by User on 2.6.2023..
//
#include <iostream>
#include <cstring>

using namespace std;

void Udvostruci(int* broj) {
    *broj *= 2;
}

void Dolijepi(char* text, const char* dodatak) {
    int nova_duljina = strlen(dodatak) + 1;

    if(text != 0) {
        nova_duljina += strlen(text);
    }
    char* novi_text = new char[nova_duljina];

    char* odrediste = novi_text;

    if (text != 0) {
        const char* polaziste = text;
        while (*polaziste != 0) {
            *odrediste++ = *polaziste++;
        }
    }

    while (*dodatak != 0) {
        *odrediste++ = *dodatak++;
    }
    *odrediste = '\0';
    text = novi_text;
}

char* Dolijepi2(char* text, const char* dodatak) {
    int nova_duljina = strlen(dodatak) + 1;

    if(text != 0) {
        nova_duljina += strlen(text);
    }
    char* novi_text = new char[nova_duljina];

    char* odrediste = novi_text;

    if (text != 0) {
        const char* polaziste = text;
        while (*polaziste != 0) {
            *odrediste++ = *polaziste++;
        }
    }

    while (*dodatak != 0) {
        *odrediste++ = *dodatak++;
    }
    *odrediste = '\0';
    delete [] text;
    return novi_text;
}

int main() {
    // primjer 1
    int a = 5;
    Udvostruci(&a);
    cout << a << endl;

    // primjer 2
    char* pozdrav = new char[1];
    *pozdrav = '\0';
    Dolijepi(pozdrav, "Dobar dan");
    Dolijepi(pozdrav, " dobri covjece");
    cout << pozdrav << endl;
    delete[] pozdrav;

    // primjer 3
    pozdrav = 0;
    pozdrav = Dolijepi2(pozdrav, "Dobar dan");
    pozdrav = Dolijepi2(pozdrav, " dobri covjece");
    cout << pozdrav << endl;
    delete[] pozdrav;

    // primjer 4
//    char pozdrav2[40];
//    pozdrav2 = Dolijepi2(pozdrav2, "Dobar dan");
    return 0;
}