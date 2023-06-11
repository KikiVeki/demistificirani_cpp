//
// Created by User on 11.6.2023..
//
#include <iostream>
using namespace std;

class Vektor{
private:
    double ax, ay;
    Vektor();
public:
    Vektor(double x, double y);
    void NekaFja();
};

void Vektor::NekaFja() {
//    Vektor priv;
}

class Jedinac{
public:
    static Jedinac& Instanca() {
        static Jedinac samo_jedan;
        return samo_jedan;
    }
private:
    Jedinac() {}
    ~Jedinac() {}
public:
    Jedinac(const Jedinac&) = delete;
    Jedinac& operator=(const Jedinac&) = delete;
    void IspisiVrijeme() {
        cout << "Vrijeme" << endl;
    }
};

class Neunistiva{
private:
    ~Neunistiva() {}
};

class Samounistavajuca{
public:
    Samounistavajuca() : brojac{0} {}
private:
    int brojac;
    ~Samounistavajuca() {}
public:
    Samounistavajuca* Pristupi() {
        ++brojac;
        return this;
    }
    void Odstupi() {
        if (--brojac == 0) {
            delete this;
        }
    }
};

int main() {
//    Vektor v1;
//    Vektor v2{12, 3};
    Jedinac::Instanca().IspisiVrijeme();
//    Neunistiva nu;
    Samounistavajuca* s = new Samounistavajuca();
    Samounistavajuca* s1 = s->Pristupi();
    Samounistavajuca* s2 = s->Pristupi();
    s1->Odstupi();
    Samounistavajuca* s3 = s->Pristupi();
    s2->Odstupi();
    s3->Odstupi();
    return 0;
}
