//
// Created by User on 4.6.2023..
//
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double Mocnica(double baza, double potencija) {
    if (baza <= 0) {
        throw domain_error("Baza mora biti veca od nule!");
    }
    double rezultat = exp(potencija * log(baza));
    if (isinf(rezultat)) {
        throw range_error("Rezultat je prevelik za tip double");
    }
    return rezultat;
}

double Mocnica(double baza, int potencija) {
    int brojac = potencija > 0 ? potencija : -potencija;
    double rezultat = 1;
    while(brojac-- > 0) {
        rezultat *= baza;
    }
    if (isinf(rezultat)) {
        throw range_error("Rezultat je prevelik/premali za double");
    }
    return potencija > 0 ? rezultat : 1 / rezultat;
}


int main() {

    cout << Mocnica(-3,3) << endl;
    cout << Mocnica(-3.,3) << endl;
    cout << Mocnica(-2.,3.) << endl;
    return 0;
}