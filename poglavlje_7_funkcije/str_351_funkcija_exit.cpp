//
// Created by User on 7.6.2023..
//
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double Ln(double x) {
    if (x <= 0) exit(1);
    return log(x);
}

int main() {
    cout << Ln(2) << endl;
    cout << Ln(0) << endl;
    cout << Ln(5) << endl;
    return 0;
}