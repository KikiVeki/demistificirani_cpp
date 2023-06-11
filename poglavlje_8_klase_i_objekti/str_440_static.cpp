//
// Created by User on 11.6.2023..
//
#include <iostream>
using namespace std;

// str 440
//class Brojeni{
//private:
//    static int brojac;
//    int moj_broj;
//public:
//    Brojeni();
//    ~Brojeni();
//};
//
//Brojeni::Brojeni() : moj_broj(brojac++){
//    cout << "Stvoren element br.:" << moj_broj << endl;
//}
//
//Brojeni::~Brojeni(){
//    cout << "Unisten element br.:" << moj_broj << endl;
//}

// str 441
class Brojeni{
public:
    static int brojac;
    int moj_broj;
    void IspisiBrojace();
    static int VrijednostBrojaca() {return brojac;}
//    static int VrijednostMogBroja() {return moj_broj;}

};


void Brojeni::IspisiBrojace() {
    cout << "Brojac: " << brojac << endl;
    cout << "Moj broj: " << moj_broj << endl;
}

class Obj{
    static Obj staticki_clan;
    Obj& ref;
    Obj* pok;
//    Obj nestaticki_clan;
};

class Vektor{
private:
    double ax, ay;
    static const Vektor null_vektor;
    static const Vektor x_jedinica;
    static const Vektor y_jedinica;
public:
    constexpr Vektor() : ax{0}, ay{0} {}
    Vektor(double x, double y);
};

Vektor::Vektor(double x, double y) {
    ax = x;
    ay = y;
}

int Brojeni::brojac = 0;
const Vektor Vektor::null_vektor{};
const Vektor Vektor::x_jedinica{1, 0};
const Vektor Vektor::y_jedinica{0, 1};

int a;
class Param{
private:
    int a;
    static int b;
public:
    void F1(int = b);
    void F2(int = ::a);
//    void F3(int = a);
};

int main() {
    Brojeni bb;
    Brojeni::brojac = 5;
    ++bb.brojac;
    bb.IspisiBrojace();

    cout << Brojeni::VrijednostBrojaca() << endl;
    cout << bb.VrijednostBrojaca() << endl;

    int* pok = &Brojeni::brojac;
    int (*pok_funkciju)() = Brojeni::VrijednostBrojaca;
    return 0;
}
