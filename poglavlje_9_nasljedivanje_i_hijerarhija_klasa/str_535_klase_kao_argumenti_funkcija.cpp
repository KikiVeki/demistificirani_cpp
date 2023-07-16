//
// Created by User on 16.7.2023..
//
#include <iostream>
using namespace std;


//////////////////

enum class Boja{Bijela, Zuta, Zelena, Crvena, Plava, Crna};

class GrafickiObjekt{
public:
    Boja boja;
};

class Linija: public GrafickiObjekt{
public:
    int x1;
    void Crtaj();
};

////////////////////////////

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


//////////////////////////

class A{};
class B: public A{};
class C: public B{};

void Rastegni(GrafickiObjekt& obj);
void Rastegni(Linija& obj);

void Deformiraj(GrafickiObjekt& obj);
void PopuniNulama(void* pok);

void ProduljiLiniju(Linija& obj);

void Obradi(Atom& obj);
void Obradi(Vektor& obj);

void Funkcija(A& obj);
void Funkcija(B& obj);

int main() {
    Linija lin{};
    Rastegni(lin);
    Deformiraj(lin);
    PopuniNulama(&lin);
    GrafickiObjekt go{};
//    ProduljiLiniju(go);

    LVektor lv{};
//    Obradi(lv);
    Obradi(static_cast<Vektor&>(lv));

    C objC{};
    Funkcija(objC);

    return 0;
}
