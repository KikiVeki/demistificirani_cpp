//
// Created by User on 11.7.2023..
//

#include <iostream>
using namespace std;

class Vektor{
    friend void ZbrojiVektore(const Vektor& a, const Vektor& b, Vektor& rez);
    friend Vektor ZbrojiVektore(const Vektor& a, const Vektor& b);
private:
    static int brojac;
    int red_br{0};
    double ax{0.0}, ay{0.0};
public:
    Vektor(double x = 0, double y = 0);
    Vektor(const Vektor& v);
    ~Vektor();
    double DayX() const noexcept {return ax;}
    double DayY() const noexcept {return ay;}
    void PostaviXY(double x, double y) {ax = x; ay = y;}
    void IspisiVektor() const;
};

int Vektor::brojac = 0;

Vektor::Vektor(double x, double y): ax(x), ay(y), red_br(++brojac) {
    cout << "Stovren vektor br " << red_br << endl;
    cout << "X: " << ax << ", Y: " << ay << endl;
}

Vektor::Vektor(const Vektor& v): ax(v.ax), ay(v.ay), red_br(++brojac) {
    cout << "Stovren vektor pomocu konstruktora kopije " << endl;
    cout << "X: " << ax << ", Y: " << ay << endl;
}

Vektor::~Vektor() {
    cout << "Unisten vektor br " << red_br << endl;
    cout << "X: " << ax << ", Y: " << ay << endl;
}

void ZbrojiVektore(const Vektor& a, const Vektor& b, Vektor& rez) {
    cout << "Zbrajam" << endl;
    rez.ax = a.ax + b.ax;
    rez.ay = a.ay + b.ay;
    cout << "Zbrojio sam!" << endl;
}

Vektor ZbrojiVektore(const Vektor& a, const Vektor& b) {
    cout << "Usao u ZbrojiVektore" << endl;
    Vektor rez = {a.DayX() + b.DayX(), a.DayY() + b.DayY()};
    return rez;
}

void NaNulu(Vektor v) {
    cout << "Usao u NaNulu" << endl;
    v.PostaviXY(0, 0);
    cout << "Postavio sam!" << endl;
}

void Vektor::IspisiVektor() const {
    cout << "Ispis (" << ax << ", " << ay << ")" << endl;
}

int main() {
    // puno primjera
////    Vektor a{10.0, 2.8};
////    Vektor b{-2.0, 5.0};
//    Vektor c;
////    ZbrojiVektore(a, b, c);
//    ZbrojiVektore(Vektor{10.0, 2.8}, Vektor{-2.0, 5.0}, c);
//    cout << c.DayX() << " " << c.DayY() << endl;ž

//    cout << "Ulaz u main!" << endl;
//    Vektor c;
//    cout << "Pozivam ZbrojiVektore" << endl;
//    ZbrojiVektore(Vektor{10.0, 2.8}, Vektor{-2.0, 5.0}, c);
//    cout << "Zavrsavam" << endl;
//
//    cout << "Prije izraza" << endl;
//    Vektor{12.0, 3.0}.IspisiVektor();
//    cout << "Nakon izraza" << endl;
//
//    Vektor d{12.0, 3.0};
//    cout << "Pozivam NaNulu" << endl;
//    NaNulu(d);
//    cout << "Zavrsavam!" << endl;

    cout << "Ulaz u main!" << endl;
    Vektor a{12.0, 3.0};
    Vektor b{-2.0, -6-+.0};
    Vektor c;
    cout << "Ulaz u ZbrojiVektore" << endl;
    c = ZbrojiVektore(a, b);
    cout << "Zavrsavam!" << endl;
    return 0;
}
