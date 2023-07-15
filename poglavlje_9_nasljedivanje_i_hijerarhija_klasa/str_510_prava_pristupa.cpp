//
// Created by User on 15.7.2023..
//
//
// Created by User on 15.7.2023..
//
#include <iostream>
using namespace std;

enum class Boja{Bijela, Zuta, Zelena, Crvena, Plava, Crna};

class GrafickiObjekt{
private:
    int brojac;

protected:
    Boja boja;
public:
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
    void Crtaj();
    void Translatiraj(int vx, int vy);
    void Rotiraj(int cx, int cy, int kut);
};
 

int main() {
    Linija linic{};
    Linija* pok_lini = &linic;
    GrafickiObjekt* pok_grob = pok_lini;
    pok_grob->PostaviBoju(Boja::Plava);

    GrafickiObjekt& ref_grob = linic;
    ref_grob.CitajBoju();
    return 0;
}
