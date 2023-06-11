//
// Created by User on 9.6.2023..
//
#include <iostream>
#include <vector>
using namespace std;

class Vektor{
private:
    double ax{0.};
    double ay{0.};
public:
    constexpr Vektor() : ax{0}, ay{0} {}
//    Vektor() = default;
    Vektor(double x, double y);
    Vektor(const Vektor& ref_vektor);

    void PostaviXY(double x, double y){ax = x; ay = y;}
    double DajX() const noexcept {return ax;}
    double DajY() const noexcept {return ay;}
//    Vektor& MnoziSkalarom(double skalar);
};

Vektor::Vektor(const Vektor& ref_vektor) :
ax(ref_vektor.ax), ay(ref_vektor.ay){}

Vektor::Vektor(double x, double y) {
    ax = x;
    ay = y;
}


class Par{
public:
    Vektor& vektor_prvi;
    Vektor& vektor_drugi;

    Par(Vektor& v1, Vektor& v2) : vektor_prvi(v1), vektor_drugi(v2) {}
};

int main() {
    Vektor v{};
    Vektor v1{12, 3};
    Vektor v2{v1};
    Vektor v3 = v1;
    Vektor a{10.0, 2.0}, b{-2.0, -5.0};
    Par vp{a, b};

    vp.vektor_prvi.PostaviXY(-3.0, 24.5);
    cout << a.DajX() << endl;

    vector<Vektor> niz_vektora{{3, 2}, {}};
    niz_vektora.push_back(Vektor{5, 7});
    cout << niz_vektora[1].DajX() << ", " << niz_vektora[1].DajY() << endl;

    Vektor niz[3];
    Vektor niz2[3]{Vektor{12, 3}, Vektor{}, Vektor{-3, 5}};
    Vektor* niz3 = new Vektor[3];
    delete[] niz3;
    return 0;
}


