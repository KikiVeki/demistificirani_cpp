//
// Created by User on 9.6.2023..
//
#include <iostream>

using namespace std;


class Pristup {
public:
    int a, b;
    void FunkcijaJavna(int brojac);
    void ZbrojiC(const Pristup& drugi);
private:
    int c;
protected:
    int d;
    int FunkcijaZasticena();
};

void Pristup::FunkcijaJavna(int brojac) {
    a = brojac;
    c = a + 5;
    FunkcijaZasticena();
}

int Pristup::FunkcijaZasticena() {return 0;}

void Pristup::ZbrojiC(const Pristup &drugi) {
    c += drugi.c;
}

int main() {
    Pristup x;
    x.a = x.b = 6;
    x.FunkcijaJavna();
    cout << x.c << endl;
    x.FunkcijaZasticena();
    return 0;
}