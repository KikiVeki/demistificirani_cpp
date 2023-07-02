//
// Created by User on 2.7.2023..
//
#include <iostream>
using namespace std;

class Niz{
public:
    Niz() {duljina = 10; pok_niz = new int[duljina];}
    int Zbroji();
private:
    int duljina;
    int* pok_niz;
};

int Niz::Zbroji() {
    int duljina = Niz::duljina;
    int s = 0;
    while (duljina) {
        s += pok_niz[--duljina];
    }
    return s;
}

int main() {
    return 0;
}
