//
// Created by User on 16.7.2023..
//
#include <iostream>
using namespace std;

class Atom{
private:
    Atom* pok_sljedeci;
    Atom* pok_prethodni;
public:
};

class Vektor{
private:
    double ax, ay;
public:
};

class LVektor: public Atom, public Vektor{
public:
    int redni_broj;
};

enum class Boja{Bijela, Zuta, Zelena, Crvena, Plava, Crna};

class GrafickiObjekt{
public:
    Boja boja;
};

class Linija: private GrafickiObjekt{
public:
    int x1;
    void Crtaj();
};

void Linija::Crtaj() {
    // pr1
//    Boja Linija::*pok_clan = &GrafickiObjekt::boja;

    //pr2
    int GrafickiObjekt::*pok_clan;
    //pok_clan = &Linija::x1;
    pok_clan = static_cast<int GrafickiObjekt::*>(&Linija::x1);

    GrafickiObjekt go;
    go.*pok_clan = 8;
    this->*pok_clan = 9;
}

int main() {

    LVektor lv{};
    Vektor* pv = &lv;
    LVektor* plv = static_cast<LVektor*>(pv);
    plv->redni_broj = 5;

    Vektor v{};
    Vektor* pv1 = &lv;
    LVektor* plv1 = static_cast<LVektor*>(pv1);
    plv1->redni_broj = 5;
    return 0;
}
