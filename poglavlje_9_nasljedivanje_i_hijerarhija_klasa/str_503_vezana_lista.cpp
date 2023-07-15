//
// Created by User on 15.7.2023..
//
#include <iostream>
using namespace std;

class Atom{
private:
    Atom* pok_sljedeci;
    Atom* pok_prethodni;
public:
    Atom* Sljedeci() const {return pok_sljedeci;}
    Atom* Prethodni() const {return pok_prethodni;}
    void StaviSljedeci(Atom* pok) {pok_sljedeci = pok;}
    void StaviPrethodni(Atom* pok) {pok_prethodni = pok;}
};

class Lista{
private:
    Atom* glava;
    Atom* rep;
public:
    Lista() : glava(nullptr), rep(nullptr){}
    Atom* AmoGlavu() const {return glava;}
    Atom* AmoRep() const {return rep;}
    void UgurajClan(Atom* pok, Atom* iza_kojeg = nullptr);
    void GoniClan(Atom* pok);
};


void Lista::UgurajClan(Atom *pok, Atom *iza_kojeg) {
    if (iza_kojeg != nullptr) {
        if(iza_kojeg->Sljedeci() != nullptr) {
            iza_kojeg->Sljedeci()->StaviPrethodni(pok);
        } else {
            rep = pok;
        }
        pok->StaviSljedeci(iza_kojeg->Sljedeci());
        iza_kojeg->StaviSljedeci(pok);
    } else {
        pok->StaviSljedeci(glava);
        if (glava != nullptr) {
            glava->StaviPrethodni(pok);
        }
        glava = pok;
    }
    pok->StaviPrethodni(iza_kojeg);
}

void Lista::GoniClan(Atom *pok) {
    if (pok->Sljedeci() != nullptr) {
        pok->Sljedeci()->StaviPrethodni(pok->Prethodni());
    } else {
        rep = pok->Prethodni();
    }
    if (pok->Prethodni() != nullptr) {
        pok->Prethodni()->StaviSljedeci(pok->Sljedeci());
    } else {
        glava = pok->Sljedeci();
    }
}

class LVektor: public Atom {
private:
    double ax, ay;
public:
    LVektor(double a = 0, double b = 0) : ax(a), ay(b) {}
    void PostaviXY(double x, double y) {ax = x; ay = y;}
    double DayX() const noexcept {return ax;}
    double DayY() const noexcept {return ay;}
};

int main() {
    Lista lst;
    LVektor lv1{10.0, 20.0};
    LVektor lv2{-5.0, -6.0};
    lst.UgurajClan(&lv1);
    lst.UgurajClan(&lv2);

    LVektor* pok = static_cast<LVektor*>(lst.AmoGlavu());
    while (pok) {
        cout << "(" << pok->DayX() << ", " << pok->DayY() << ")" << endl;
        pok = static_cast<LVektor*>(pok->Sljedeci());
    }
    return 0;
}
