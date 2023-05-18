//
// Created by User on 16.5.2023..
//
#include "iostream"
#include "fstream"

//template
using namespace std;

int main() {

    constexpr int nmax = 100;
    ifstream ulazni_tok("C:\\Users\\User\\CLionProjects\\demistificirani_cpp\\poglavlje_4\\brojevi.txt");
    if(!ulazni_tok) {
        cerr << "Ne mogu otvoriti traženu datoteku!" << endl;
        return 1;
    }

    double brojevi[nmax];
    int n = 0;
    double broj;

    while (ulazni_tok >> broj)
    {
        if (n >= nmax)
        {
            cerr << "Previse podataka" << endl;
            return 2;
        }
        brojevi[n++] = broj;
    }

    if(n == 0) {
        cerr << "Nema podataka" << endl;
        return 3;
    }

    for (int i = n-1; i > 0; --i) {
        bool zamjena = false;
        for (int j = 0; j < i; ++j) {
            if (brojevi[j + 1] < brojevi[j]) {
                swap(brojevi[j], brojevi[j + 1]);
//                auto privremeni = brojevi[j];
//                brojevi[j] = brojevi[j + 1];
//                brojevi[j + 1] = privremeni;
                zamjena = true;
            }
        }
        if (!zamjena) break;
    }

    cout << "Brojevi slozeni po velicini:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << brojevi[i] << endl;
    }

    return 0;
}