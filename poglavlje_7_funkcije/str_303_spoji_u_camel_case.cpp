//
// Created by User on 3.6.2023..
//
#include <iostream>
#include <string>

using namespace std;

void SpojiUDevu(const char* prvi, const char* drugi, char* spojeni) {
    char* indeks = spojeni;
    if (prvi) {
        *(indeks++) = toupper(*(prvi++));
        while (*prvi) {
            *(indeks++) = *(prvi++);
        }
    }
    if (drugi) {
        *(indeks++) = toupper(*(drugi++));
        while (*drugi) {
            *(indeks++) = *(drugi++);
        }
    }
    *indeks = '\0';
}

// sa str 306
string SpojiUDevu2(const char* prvi, const char* drugi) {
    string spojeni{prvi};
    if(!spojeni.empty()) {
        spojeni[0] = toupper(spojeni[0]);
    }
    string nastavak{drugi};
    if(!spojeni.empty()) {
        nastavak[0] = toupper(nastavak[0]);
    }
    return spojeni.append(nastavak);
}


int main() {
    char rezultat[80];
    SpojiUDevu("pero", "laki", rezultat);
    cout << rezultat << endl;
    string partizanski_pokret = SpojiUDevu2("partizani", "ustase");
    cout << partizanski_pokret << endl;
    return 0;
}