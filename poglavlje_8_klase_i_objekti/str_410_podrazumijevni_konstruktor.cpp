//
// Created by User on 9.6.2023..
//
#include <iostream>

using namespace std;

class Vektor{
private:
    double ax{0.};
    double ay{0.};
public:
    Vektor() = default;
    Vektor(double x, double y);
    Vektor(const Vektor& ref_vektor);

//    void PostaviXY(double x, double y){ax = x; ay = y;}
//    double DajX() const noexcept {return ax;}
//    double DajY() const noexcept {return ay;}
//    Vektor& MnoziSkalarom(double skalar);
};

Vektor::Vektor(const Vektor& ref_vektor) :
ax(ref_vektor.ax), ay(ref_vektor.ay){}


int main() {
    Vektor v{};
    Vektor v1{12, 3};
    Vektor v2{v1};
    Vektor v3 = v1;
    return 0;
}


