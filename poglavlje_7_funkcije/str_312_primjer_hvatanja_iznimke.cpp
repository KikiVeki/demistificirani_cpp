//
// Created by User on 3.6.2023..
//
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

double KvaKorijen(double broj) {
    if (broj < 0) {
        throw domain_error("negativni argument funkciji KvaKorijen");
    }
    return sqrt(broj);
}

int main() {
    cout << KvaKorijen(4) << endl;
    cout << KvaKorijen(3) << endl;
    cout << KvaKorijen(-4) << endl;

    return 0;
}