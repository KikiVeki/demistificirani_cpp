//
// Created by User on 3.6.2023..
//
#include <iostream>
#include <iomanip>

using namespace std;

void IspisiMatricu(double** m, int redaka, int stupaca){
    for (int r = 0; r < redaka; ++r) {
        for (int s = 0; s < stupaca; ++s) {
            cout << setw(10) << ((double *)m)[r*stupaca+s];
        }
        cout <<  endl;
    }
}

int main() {
    int redaka = 2;
    const int stupaca = 3;
    double (*matrica)[stupaca] = new double[redaka][stupaca];
    matrica[0][0] = 1.1;
    matrica[0][1] = 1.2;
    matrica[0][2] = 1.3;
    matrica[1][0] = 2.1;
    matrica[1][1] = 2.2;
    matrica[1][2] = 2.3;

    IspisiMatricu((double **)(matrica), redaka, stupaca);
    delete [] matrica;

    return 0;
}