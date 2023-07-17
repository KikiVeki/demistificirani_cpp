//
// Created by User on 17.7.2023..
//
#include <iostream>
#include <vector>

using namespace std;

enum class Boja{Bijela, Zuta, Zelena, Crvena, Plava, Crna};

class GrafickiObjekt{

private:
    Boja boja;
public:
    void PostaviBoju(Boja nova) {boja = nova;}
    Boja CitajBoju() const noexcept {return boja;}
//    virtual void Crtaj() = 0;
//    virtual void Brisi() = 0;
//    virtual void Translatiraj(int, int) = 0;
    virtual void Crtaj();
    virtual void Brisi();
    virtual void Translatiraj(int, int);
    void Pomakni(int px, int py);
    virtual void Rotiraj(int, int, int) {}
    virtual ~GrafickiObjekt();
    virtual GrafickiObjekt* Kloniraj() const {
        return new GrafickiObjekt(*this);
    }
};

void GrafickiObjekt::Pomakni(int px, int py) {
    Brisi();
    Translatiraj(px, py);
    Crtaj();
}

class Linija: public GrafickiObjekt{
private:
    int x1, y1, x2, y2;
public:
    Linija(){}
    Linija(int px, int py, int zx, int zy) :
             x1(px), y1(py), x2(zx), y2(zy) {}
    void Crtaj() override;
    void Translatiraj(int vx, int vy) override;
    void Brisi() override;
    void Rotiraj(int cx, int cy, int kut) override;
//    GrafickiObjekt* Kloniraj() const override {
//        return new GrafickiObjekt(*this);
//    }
    Linija* Kloniraj() const override {
        return new Linija(*this);
    }
};

class LinijaSaStrelicom: public Linija{
private:
    int x1, y1, x2, y2;
public:
    void Crtaj() override {
        Linija::Crtaj();
        //jos koda
    }
};

class A{
public:
    void Funkcija() {cout << "A::Funkcija()" << endl;}
};

class B: public A{
public:
    virtual void Funkcija() {cout << "B::Funkcija()" << endl;}
};

class C: public B{
public:
    virtual void Funkcija() override {cout << "C::Funkcija()" << endl;}
};


class Bazna{
public:
    void Nevirutalna() {cout << "Bazna::Nevirtualna()" << endl;}
    virtual void Virutalna() {cout << "Bazna::Virtualna()" << endl;}
};

class Izvedena: public Bazna{
public:
    void Nevirutalna() {cout << "Izvedena::Nevirtualna()" << endl;}
    void Virutalna() override {cout << "Izvedena::Virtualna()" << endl;}
};


int main() {
    C objc;
    A* pok_a = &objc;
    B* pok_b = &objc;
    pok_a->Funkcija();
    pok_b->Funkcija();

    Bazna* pok_bazna = new Bazna{};
    Izvedena* pok_izvedena = new Izvedena{};
    pok_bazna->Nevirutalna();
    pok_izvedena->Nevirutalna();
    pok_bazna->Virutalna();
    pok_izvedena->Virutalna();

    Linija duzina{};
    GrafickiObjekt* pok_go = &duzina;
    pok_go->Crtaj();
    GrafickiObjekt& ref_go = duzina;
    ref_go.Crtaj();

    duzina.GrafickiObjekt::Crtaj();
    pok_go->GrafickiObjekt::Crtaj();
    pok_go->GrafickiObjekt::Pomakni(5,7);

    GrafickiObjekt grob;
    GrafickiObjekt& r_grob = grob;
    Linija lin;
    r_grob = lin;
    return 0;
}
