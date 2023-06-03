//
// Created by User on 3.6.2023..
//
#include <iostream>
#include <string>


using namespace std;

struct Osoba{
    string ime;
    string prezime;
};

Osoba* DajOsobu(int oib) {
    switch (oib) {
        case 1:
            return new Osoba{"Dora", "Krupic"};
        case 2:
            return new Osoba{"Segrt", "Hlapic"};
        default:
            return nullptr;
    }
}

int main() {
    Osoba* a = DajOsobu(2);
    cout << a->ime << " " << a->prezime << endl;
    delete a;
    return 0;
}