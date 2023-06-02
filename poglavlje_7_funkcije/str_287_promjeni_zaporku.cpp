//
// Created by User on 2.6.2023..
//
#include <iostream>
#include <cstring>

using namespace std;

char* Preslikaj(char* odrediste, const char* izvoriste) {
    delete[]  odrediste;
    int duljina = strlen(izvoriste);
    odrediste = new char[duljina + 1];
    do {
        odrediste[duljina] = izvoriste[duljina];
    } while (--duljina>= 0);
    return odrediste;
}

bool PromjeniZaporku(char** zaporka) {
    char novi_unos[40];
    if (*zaporka != 0) {
        cout << "upisi staru zaporku: ";
        cin >> novi_unos;

        int i = 0;
        while (novi_unos[i] != 0) {
            if (novi_unos[i] != (*zaporka)[i]) {
                cout << "Neispravna stara zaporka!" << endl;
                return false;
            }
            ++i;
        }
    }
    cout << "Upisi novu zaporku: ";
    cin >> novi_unos;
    *zaporka = Preslikaj(*zaporka, novi_unos);
    return true;
}

bool PromjeniZaporku2(char*& zaporka) {
    char novi_unos[40];
    if (zaporka != 0) {
        cout << "upisi staru zaporku: ";
        cin >> novi_unos;

        int i = 0;
        while (novi_unos[i] != 0) {
            if (novi_unos[i] != zaporka[i]) {
                cout << "Neispravna stara zaporka!" << endl;
                return false;
            }
            ++i;
        }
    }
    cout << "Upisi novu zaporku: ";
    cin >> novi_unos;
    zaporka = Preslikaj(zaporka, novi_unos);
    return true;
}

int main() {
    char* zaporka = 0;

    // primjer 1
//    if(PromjeniZaporku(&zaporka))
//        cout << "Nova zaporka: " << zaporka << endl;
//
//    if(PromjeniZaporku(&zaporka))
//        cout << "Nova zaporka: " << zaporka << endl;
//
//    delete[] zaporka;

    // primjer 2
    if(PromjeniZaporku2(zaporka))
        cout << "Nova zaporka: " << zaporka << endl;

    if(PromjeniZaporku2(zaporka))
        cout << "Nova zaporka: " << zaporka << endl;

    delete[] zaporka;
    return 0;
}