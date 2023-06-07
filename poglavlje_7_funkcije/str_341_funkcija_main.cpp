//
// Created by User on 7.6.2023..
//
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    cout << argc << endl;
    if(argc < 2) {
        cerr << "Nije navedeno ime datoteke!" << endl;
        return 1;
    }

    for (int i = 0; i < argc; ++i) {
        ifstream fajla(argv[i]);
        if(!fajla.is_open()) {
            cerr << "Ne mogu otvoriti datoteku: " << argv[i] << endl;
        } else {
            cout << "Sadrzaj datoteke " << argv[i] << endl;
            for (char znak; (znak = fajla.get()) != EOF;) {
                cout << znak;
            }
            cout << endl;
        }
    }
    return 0;
}