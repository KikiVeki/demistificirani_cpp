//
// Created by User on 9.6.2023..
//
#include <iostream>
#include <cmath>

using namespace std;

class Pravac;
class Tocka{
    friend double UdaljenostTockaPravac(const Pravac& p, const Tocka& t);
private:
    double x, y;
};

class Pravac{
    friend double UdaljenostTockaPravac(const Pravac& p, const Tocka& t);
private:
    double k, l;
};

double UdaljenostTockaPravac(const Pravac& p, const Tocka& t){
    return abs((p.k * t.x - p.l * t.y) / sqrt(p.k * p.k + 1));
};

int main() {
    Tocka t;
    Pravac p;
    cout << UdaljenostTockaPravac(p, t) << endl;
    return 0;
}