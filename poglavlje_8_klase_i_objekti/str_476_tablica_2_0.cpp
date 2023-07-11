//
// Created by User on 11.7.2023..
//
#include <iostream>
using namespace std;

class Tablica{
private:
    int* elementi;
    size_t broj_elemenata, duljina;

public:
    Tablica();
    Tablica(size_t pocetna_duljina);
    Tablica(Tablica&& tablica) noexcept;
    Tablica(initializer_list<int> lista);
    Tablica(const Tablica& tablica);
    void PovecajNa(size_t nova_duljina);
    void DodajElement(int novi_element);
    void BrisiElement(size_t pozicija);
    int& Element(size_t pozicija) const;
};

int& Tablica::Element(size_t pozicija) const {
    return elementi[pozicija];
}

Tablica::Tablica(Tablica&& tablica)
noexcept     : elementi(tablica.elementi), duljina(tablica.duljina), broj_elemenata(tablica.broj_elemenata) {
    tablica.elementi = nullptr;
    tablica.duljina = 0;
    tablica.broj_elemenata = 0;
}

Tablica::Tablica(initializer_list<int> lista)
        : elementi{new int[lista.size()]},
          broj_elemenata{0},
          duljina{lista.size()}{
    for (const int& clan: lista) {
        elementi[broj_elemenata++] = clan;
    }
}

Tablica::Tablica(const Tablica &tablica)
        : elementi{new int[tablica.duljina]},
          duljina{tablica.duljina},
          broj_elemenata{tablica.broj_elemenata}
{
    for (size_t i = 0; i < broj_elemenata; ++i) {
        elementi[i] = tablica.elementi[i];
    }
}

class ProsjekOcjena{
private:
    Tablica ocjene;
public:
    void DodajOcjenu(int ocjena);
    double Prosjek() const;
    ProsjekOcjena(const Tablica& ocjene) : ocjene(ocjene) {}
    ProsjekOcjena(Tablica&& ocjene) : ocjene(std::move(ocjene)) {}
    // efikasnije? imati samo ovo
//    ProsjekOcjena(Tablica ocjene) : ocjene(std::move(ocjene)) {}

};

Tablica NapuniTablicu(int n) {
    Tablica t(n);
    for (int i = 0; i < n; i++) {
        t.DodajElement(i);
    }
    return t;
}

int main() {
    Tablica t(NapuniTablicu(20));
    Tablica prvi_semestar{2,3,1,4};
    ProsjekOcjena prosjek1(prvi_semestar);
    ProsjekOcjena prosjek2(Tablica{5,4,4,5});
    return 0;
}
