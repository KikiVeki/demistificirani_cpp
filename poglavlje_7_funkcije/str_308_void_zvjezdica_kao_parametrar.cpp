//
// Created by User on 3.6.2023..
//
#include <iostream>

using namespace std;

enum class Tip{
    CijeliBroj, DecimalniBroj, ZnakovniNiz
};




































































































































































































































































































































































































































































































































































































































































void Ispisi(void* podatak, Tip tip_podatka) {
    switch (tip_podatka) {
        case Tip::CijeliBroj:
            cout << *static_cast<int*> (podatak) << endl;
            break;
        case Tip::DecimalniBroj:
            cout << *static_cast<double *> (podatak) << endl;
            break;
        case Tip::ZnakovniNiz:
            cout << static_cast<char *> (podatak) << endl;
            break;
    }
}


int main() {
    int cijeli_brij = 10;
    Ispisi(&cijeli_brij, Tip::CijeliBroj);

    double decimalac = 3.4;
    Ispisi(&decimalac, Tip::DecimalniBroj);
    Ispisi((void *) "Mujo kuje konja", Tip::ZnakovniNiz);
    return 0;
}