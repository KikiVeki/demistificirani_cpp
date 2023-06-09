//
// Created by User on 9.6.2023..
//
#include <iostream>
#include <cmath>
using namespace std;

// los nacin!
//struct Vektor{
//    double ax, ay;
//};
//
//void MnoziVektorSkalarom(Vektor v, double skalar) {
//    v.ax *= skalar;
//    v.ay *= skalar;
//}
enum class Zakret{Udesno, Nasuprot, Ulijevo};

class Vektor{
    friend Vektor ZbrojiVektore(const Vektor& a, const Vektor& b);
public:
    double ax, ay;
    Vektor& MnoziSkalarom(double skalar);
    Vektor& ZbrojiSa(double zx, double zy);
    void Zakreni(Zakret zakret);
    void Zakreni(double radijana);
};

// str 392
//class Vektor{
//private:
//    double ax, ay;
//public:
//    void PostaviXY(double x, double y){ax = x; ay = y;}
//    double DajX() const noexcept {return ax;}
//    double DajY() const noexcept {return ay;}
//    Vektor& MnoziSkalarom(double skalar);
//    Vektor& ZbrojiSa(double zx, double zy);
//    void Zakreni(Zakret zakret);
//    void Zakreni(double radijana);
//};

Vektor& Vektor::MnoziSkalarom(double skalar) {
    ax *= skalar;
    ay *= skalar;
    return *this;
}

Vektor& Vektor::ZbrojiSa(double zx, double zy) {
    ax += zx;
    ay += zy;
    return *this;
}

void Vektor::Zakreni(Zakret zakret) {
    switch (zakret) {
        case Zakret::Nasuprot:
            ax = -ax;
            ay = -ay;
            break;
        case Zakret::Udesno:
            std::swap(ax, ay);
            ay = -ay;
            break;
        case Zakret::Ulijevo:
            std::swap(ax, ay);
            ax = -ax;
            break;
    }
}

void Vektor::Zakreni(double radijana) {
    auto x = ax * cos(radijana) - ay * sin(radijana);
    auto y = ax * sin(radijana) + ay * cos(radijana);
    ax = x;
    ay = y;
}

int main() {

    // los nacin!
//    struct Vektor v;
//    MnoziVektorSkalarom(v, 5);

    Vektor v;
    v.ax = 1.0;
    v.ay = 2.0;
    v.MnoziSkalarom(5.0);

    v.Zakreni(Zakret::Udesno);
    v.Zakreni(-3.141592653);

    v.MnoziSkalarom(4).ZbrojiSa(5, -7);

    cout << v.ax << " " << v.ay << endl;
    return 0;
}