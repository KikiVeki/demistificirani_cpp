//
// Created by User on 3.6.2023..
//
#include <iostream>

using namespace std;

void Pocisti(int niz[], int duljina) {
    while (duljina--) {
        niz[duljina] = 0;
    }
}

void Pocisti2(int* prvi, int* iza_zadnjeg) {
    while (prvi != iza_zadnjeg){
        *prvi++ = 0;
    }
}

void Pocisti3(int (&niz)[5]) {
    for (int& clan : niz) {
        clan = 0;
    }
}

int main() {
    int intovi[] = {5,10, 15};
    Pocisti(intovi, 3);
    for (auto clan : intovi) {
        cout << clan << endl;
    }

    int intovi2[] = {2,4, -5, 10};
    Pocisti2(begin(intovi2), end(intovi2));
    for (auto clan : intovi2) {
        cout << clan << endl;
    }
    return 0;
}