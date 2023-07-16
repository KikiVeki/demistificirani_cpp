//
// Created by User on 15.7.2023..
//
//
// Created by User on 15.7.2023..
//
#include <iostream>
#include <vector>

using namespace std;

enum class Boja{Bijela, Zuta, Zelena, Crvena, Plava, Crna};

class GrafickiObjekt{

    friend void AnimirajBoju();
private:
    int brojac;
protected:
    Boja boja;
public:
    GrafickiObjekt(Boja b = Boja::Crna) : boja(b) {}
    void PostaviBoju(Boja nova) {boja = nova;}
    Boja CitajBoju() const noexcept {return boja;}
    void Crtaj() {}
    void Translatiraj(int, int) {}
    void Rotiraj(int, int, int) {}
    void PostaviBrojac(int br) {brojac = br;}
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
//    void Rotiraj(int cx, int cy, int kut);
    using GrafickiObjekt::Rotiraj;
    void Rotiraj(int x){
        cout << "Linija::Rotiraj(int)" << endl;
    }

    void Rotiraj(int x, int y, int z){
        cout << "Linija::Rotiraj(int, int, int)" << endl;
    }
};


void AnimirajBoju(){
    GrafickiObjekt obj{};
    ++obj.brojac;
    obj.boja == Boja::Crna;
}

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
class Poligon: public GrafickiObjekt{
public:
    void Crtaj();
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



int main() {
    Linija linic{};
    Linija* pok_lini = &linic;
    GrafickiObjekt* pok_grob = pok_lini;
    pok_grob->PostaviBoju(Boja::Plava);

    GrafickiObjekt& ref_grob = linic;
    ref_grob.CitajBoju();

    // primjer str 520
    Linija lini{};
    lini.Rotiraj(1);
    lini.Rotiraj(1, 2, 90);

    // primjer str 523
    Poligon poli{};
    GrafickiObjekt& go = poli;
    go.Crtaj();

    // nema smisla:-
//    GrafickiObjekt grafo{};
//    Poligon& polig = &grafo;
//    go->Popuni();
    return 0;
}
