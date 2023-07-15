//
// Created by User on 15.7.2023..
//
#include <iostream>
using namespace std;

enum class Boja{Bijela, Zuta, Zelena, Crvena, Plava, Crna};

class GrafickiObjekt{
private:
    Boja boja;
public:
    void PostaviBoju(Boja nova) {boja = nova;}
    Boja CitajBoju() const noexcept {return boja;}
    void Crtaj() {}
    void Translatiraj(int, int) {}
    void Rotiraj(int, int, int) {}
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
    return 0;
}
