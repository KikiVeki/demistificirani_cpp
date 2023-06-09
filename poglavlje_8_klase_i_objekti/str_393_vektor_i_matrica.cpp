//
// Created by User on 9.6.2023..
//
#include <iostream>

using namespace std;

class Vektor;

class Matrica{
private:
    double a11, a12, a21, a22;
public:
    Vektor MnoziVektorom(const Vektor& v);
};

class Vektor{
    friend Vektor ZbrojiVektore(const Vektor& a, const Vektor& b);
    friend Vektor Matrica::MnoziVektorom(const Vektor &v);
private:
    double ax, ay;
    Vektor& MnoziSkalarom(double skalar);
    Vektor& ZbrojiSa(double zx, double zy);
    void Zakreni(double radijana);
};

Vektor Matrica::MnoziVektorom(const Vektor &v) {
    Vektor rez;
    rez.ax = a11 * v.ax + a12 * v.ay;
    rez.ay = a21 * v.ax + a22 * v.ay;
    return rez;
}

Vektor ZbrojiVektore(const Vektor& a, const Vektor& b){
    Vektor c;
    c.ax = a.ax + b.ax;
    c.ay = a.ay + b.ay;
    return c;
}

int main() {
    return 0;
}