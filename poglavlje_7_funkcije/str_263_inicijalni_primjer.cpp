//
// Created by User on 31.5.2023..
//
//template
#include <iostream>
#include <iomanip>
using namespace std;

double Kvadrat(double);

int main() {
    for (int i = 0; i < 11; ++i) {
        cout << setw(5) << i << setw(10) << Kvadrat(i) << endl;
    }
    return 0;
}

double Kvadrat(double x) {
    return x * x;
}
