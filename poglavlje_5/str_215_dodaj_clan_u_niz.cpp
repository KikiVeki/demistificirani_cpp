//
// Created by User on 20.5.2023..
//
#include <iostream>

using namespace std;

int main() {

    int niz[20]{10,20,30,40,50,60,70,80,90};
    int br_clanova = 9;
    int* odrediste = niz + br_clanova;
    int novi_broj = 15;

    while (*(--odrediste) > novi_broj) {
        if (odrediste < niz) break;
        *(odrediste + 1) = *odrediste;
    }
    *(odrediste + 1) = novi_broj;
    ++br_clanova;

    for (int i = 0; i < br_clanova; ++i) {
        cout << niz[i] << endl;
    }

    return 0;
}
