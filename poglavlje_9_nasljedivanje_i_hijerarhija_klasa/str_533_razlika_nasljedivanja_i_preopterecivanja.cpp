//
// Created by User on 16.7.2023..
//
#include <iostream>
using namespace std;

class Osnovna{
public:
    void Funkcija();
};

class Izvedena: public Osnovna{
public:
    void Funkcija(int);
    void Funkcija() {Osnovna::Funkcija();}
};


class SkupNizova{
protected:
    class Elem{
        Elem(const string& niz);
    };
};

SkupNizova::Elem::Elem(const std::string &niz) {}

// mora biti public da bi mogli naslijediti iz ugnjezdene!
class NaslijediOd: public SkupNizova::Elem{};

int main() {
    Izvedena obj;
    obj.Funkcija();

    return 0;
}
