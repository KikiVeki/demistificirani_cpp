//
// Created by User on 16.5.2023..
//
#include "iostream"
#include "fstream"
#include "vector"

//template
using namespace std;

int main() {

    int nmax = 100;
    ifstream ulazni_tok("C:\\Users\\User\\CLionProjects\\demistificirani_cpp\\poglavlje_4\\brojevi.txt");
    if(!ulazni_tok) {
        cerr << "Ne mogu otvoriti traženu datoteku!" << endl;
        return 1;
    }

    vector<double> brojevi;

    for (double broj; ulazni_tok  >> broj;) {
        brojevi.push_back(broj);
    }

    if(brojevi.empty()) {
        cerr << "Nema podataka" << endl;
        return 3;
    }

    for (int i = brojevi.size() - 1; i > 0; --i) {
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
    for (auto broj: brojevi) {
        cout << broj << endl;
    }

    return 0;
}