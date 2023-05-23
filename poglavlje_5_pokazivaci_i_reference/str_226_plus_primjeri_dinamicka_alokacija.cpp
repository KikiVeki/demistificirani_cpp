//
// Created by User on 23.5.2023..
//
#include <iostream>

using namespace std;

int main() {

    // primjer1 str 226
    double neki_broj;
    double* pok_na_neki_broj = &neki_broj;
    *pok_na_neki_broj = 34.15;

    cout << neki_broj << endl;

    // primjer2 str 226
//    double* pokazivac = new double{10.45};
    double* pokazivac = new double;
    cout << *pokazivac << endl;
    delete pokazivac;

    // primjer3 str 228

    int* pok_lokal = nullptr;
    {
        int* pok_lokal = new int{20};
        cout << *pok_lokal << endl;
    }
    delete pok_lokal;
    // dobra praksa postavit na null-ptr
    pok_lokal = nullptr;

    //primjer4 str 229
    int* niz_kvadrata = new int[10];
    for (int i = 0; i < 10; ++i) {
        niz_kvadrata[i] = i * i;
    }
    delete[] niz_kvadrata;

    return 0;
}
