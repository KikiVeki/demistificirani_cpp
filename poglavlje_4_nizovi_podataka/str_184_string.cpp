//
// Created by User on 18.5.2023..
//
//template

#include <iostream>
#include <string>

using namespace std;

int main() {

    // zadatak 1
    string ime {"Marin"};
    string prezime {"Getaldic"};

    string prezime_ime;

    prezime_ime = prezime + " ";
    prezime_ime += ime;
    cout << prezime_ime << endl;

    // zadatak 2
    string petrica {"Nigdar ni bilo da ni nekak bilo \n"};
    cout << petrica << endl;

    cout << "Duljina = " << petrica.size() << endl;
    cout << "Kapacitet = " << petrica.capacity() << endl;

    petrica.insert(10, "tak ");
    cout << petrica << endl;
    cout << "Sada je duljina = " << petrica.size() << endl;
    cout << "Kapacitet = " << petrica.capacity() << endl;

    petrica.reserve(470);
    petrica.append("pak ni vazda nebu da nam nekak nebu.");

    cout << petrica << endl;
    cout << "Duljina = " << petrica.size() << endl;
    cout << "Kapacitet = " << petrica.capacity() << endl;

    return 0;
}
