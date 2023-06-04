//
// Created by User on 4.6.2023..
//
#include <iostream>

using namespace std;

constexpr double Potencija(double baza, int n) {
    double rezultat = 1;
    while (--n >= 0) rezultat *= baza;
    return rezultat;
}

constexpr double BbpRazlomci(int i) {
    return 4. / (8 * i + 1) - 2. / (8 * i + 4) - 1. / (8 * i + 5) - 1. / (8 * i + 6);
}

constexpr double  BbpClan(int i) {
    return BbpRazlomci(i) / Potencija(16, i);
}

constexpr double BbpSuma(int n) {
    double suma = 0;
    for (int i = 0; i <= n; ++i) {
        suma += BbpClan(i);
    }
    return suma;
}

constexpr double Bbp(int i) {
    if(BbpSuma(i) == BbpSuma(i + 1)) {
        return BbpSuma(i);
    }
    return Bbp(i + 1);
}

constexpr double mojPi = Bbp(0);
int main() {

    int r = 1;
    double povrsina_kruga = r * r * mojPi;
    cout << povrsina_kruga << endl;

    return 0;
}