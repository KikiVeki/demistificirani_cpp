//
// Created by User on 4.6.2023..
//
#include <iostream>
#include <cmath>

using namespace std;

double Integral(double (*f)(double), double x0, double xn, double rel_grijeh = 1.e-7, int circus_maximus = 1024);
double Podintegralna(double x);

int main() {

    cout << Integral(sin, 0, 3.14159) << endl;
    cout << Integral(Podintegralna, 0, 3.) << endl;
    return 0;
}

double Integral(double (*f)(double), double x0, double xn, double rel_grijeh, int circus_maximus) {
    long n = 1;
    const double h0 = xn-x0;
    double stara_suma = 0.;
    double suma = (f(x0) + f(xn)) / 2;
    do {
        n *= 2;
        double doprinos = 0.;
        for (long i = 0; i < n; i+=2) {
            doprinos += f(h0 * i / n + x0);
        }
        stara_suma = suma;
        suma = stara_suma / 2 + doprinos / n;
    } while (n <= circus_maximus && (suma != 0) && (abs(1. - stara_suma /suma) > rel_grijeh));
    return suma * h0;
}

double Podintegralna(double x) {
    return x * x;
}