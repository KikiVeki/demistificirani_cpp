//
// Created by User on 17.7.2023..
//
#include <iostream>
#include <vector>

using namespace std;

enum class Boja{Bijela, Zuta, Zelena, Crvena, Plava, Crna};

class GrafickiObjekt{
protected:
    Boja boja;
public:
    GrafickiObjekt(Boja b = Boja::Crna) : boja(b) {}
    void PostaviBoju(Boja nova) {boja = nova;}
    Boja CitajBoju() const noexcept {return boja;}
    virtual void Crtaj() {}
    virtual void Translatiraj(int, int) {}
    virtual void Rotiraj(int, int, int) {}
};

class Linija: public GrafickiObjekt{
private:
    int x1, y1, x2, y2;
public:
    Linija(){}
    Linija(Boja b, int px, int py, int zx, int zy) :
            GrafickiObjekt(b), x1(px), y1(py), x2(zx), y2(zy) {}
    void Crtaj();
    void Translatiraj(int vx, int vy);
    void Rotiraj(int cx, int cy, int kut);
    using GrafickiObjekt::Rotiraj;
};


void Linija::Crtaj() {
    boja = Boja::Crvena;
    GrafickiObjekt go{};
//    go.boja = Boja::Crna;
    Linija ln{};
    ln.boja = Boja::Crna;
}


// str 527, konstruktori
struct Tocka{
    int x, y;
};

using NizTocaka = vector<Tocka>;
class Poligon: public virtual GrafickiObjekt{
public:
    void Popuni(Boja boja);
    Poligon(){}
    Poligon(const NizTocaka& vrhovi) : tocke(vrhovi) {}
private:
    NizTocaka tocke;
};


class Cetverokut: public Poligon{
public:
    using Poligon::Poligon;
};

class Pravokutnik: public Cetverokut{
public:
};

class Tekst: public virtual GrafickiObjekt{
private:
    string tekst;
public:
    virtual void PostaviTeskt(const string& novi_tekst);
    virtual void Brisi();
    void Crtaj() override;
    void Translatiraj(int px, int py) override;
};

class UokvireniTekst: public Pravokutnik, public Tekst{

};
