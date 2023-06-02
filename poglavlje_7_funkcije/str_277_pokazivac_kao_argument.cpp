//
// Created by User on 2.6.2023..
//
#include <iostream>
#include <vector>

using namespace std;

void ZamjeniPok(int* prvi, int* drugi) {
    swap(*prvi, *drugi);
}

struct Tocka {
    double x;
    double y;
    int boja;
};


struct Poligon {
    int boja;
    vector<Tocka*> tocke;
};

Tocka* StvoriTocku(double x, double y, Poligon* poli) {
    if(poli) {
        Tocka* novaTocka = new Tocka{x,y,poli->boja};
        poli->tocke.push_back(novaTocka);
//        (*poli).tocke.push_back(novaTocka);
        return novaTocka;
    }
    return new Tocka{x,y,0};
}

int main() {

//    ZamjeniPok(&a, &b);

    Poligon p{15};
    Tocka* t1_poligon = StvoriTocku(2,4,&p);
    Tocka* t2_poligon = StvoriTocku(5,12.5,&p);
    Tocka* t_samostojeca = StvoriTocku(5,12.5, nullptr);

    return 0;
}