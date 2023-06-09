//
// Created by User on 9.6.2023..
//
#include <iostream>

using namespace std;

class Vektor{
private:
    double ax, ay;
public:
    Vektor(){ax = 0; ay = 0;}
    Vektor(double x, double y);

    void PostaviXY(double x, double y){ax = x; ay = y;}
    double DajX() const noexcept {return ax;}
    double DajY() const noexcept {return ay;}
    Vektor& MnoziSkalarom(double skalar);
};

Vektor::Vektor(double x, double y) {
    ax = x;
    ay = y;
}

class VektorskiPar{

//    VektorskiPar(double x1, double y1, double x2, double y2) {
//        prvi.PostaviXY(x1, y1);
//        drugi.PostaviXY(x2, y2);
//    }

    VektorskiPar(double x1, double y1, double x2, double y2) : prvi(x1, y1), drugi(x2, y2){}

private:
    Vektor prvi;
    Vektor drugi;
public:
    Vektor DajPrvog() const {return prvi;}
    Vektor DajDrugoga() const {return drugi;}
};

int main() {
    Vektor moj_inicijalizirani_vektor{3, 7};
    Vektor nul_vektor_prvi{};
    Vektor nul_vektor_drugi;

    VektorskiPar par{};
    cout << par.DajPrvog().DajX() << endl;
    cout << par.DajPrvog().DajY() << endl;
    cout << par.DajDrugoga().DajX() << endl;
    cout << par.DajDrugoga().DajY() << endl;
    return 0;
}

