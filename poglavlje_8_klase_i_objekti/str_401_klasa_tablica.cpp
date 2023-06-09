//
// Created by User on 9.6.2023..
//
#include <iostream>
#include <cassert>

using namespace std;
int globalna{0};

class Test{
public:
    int broj {++globalna};
    Test(int broj){
        cout << broj << endl;
    }
};

class Tablica{
private:
    Test test{0};
    static constexpr size_t podrazumijevna_pocetna_duljina {16};
    size_t broj_elemenata{0};
    size_t duljina{podrazumijevna_pocetna_duljina};
    int* elementi{new int[duljina]};
public:
    Tablica() {}
    Tablica(size_t pocetna_duljina);
    Tablica(const Tablica& tablica);
    void PovecajNa(size_t nova_duljina);
    void DodajElement(int novi_element);
    void BrisiElement(size_t pozicija);
    size_t BrojElemenata() const noexcept {return broj_elemenata;}
    int Element(size_t pozicija) const {return elementi[pozicija];}
//    void Inicijaliziraj(size_t pocetna_duljina);
};

// str 414
Tablica::Tablica(const Tablica &tablica)
        : elementi{new int[tablica.duljina]},
          duljina{tablica.duljina},
          broj_elemenata{tablica.broj_elemenata}
{
    for (size_t i = 0; i < broj_elemenata; ++i) {
        elementi[i] = tablica.elementi[i];
    }
}

// primjer 3
//Tablica::Tablica() : Tablica(podrazumijevna_pocetna_duljina){}

Tablica::Tablica(size_t pocetna_duljina)
        : elementi{new int[pocetna_duljina]},
//          broj_elemenata{0},
          duljina{pocetna_duljina},
          test{150}
{}

// primjer2
//Tablica::Tablica(){
//    Inicijaliziraj(podrazumijevna_pocetna_duljina);
//}
//
//Tablica::Tablica(size_t pocetna_duljina){
//    Inicijaliziraj(pocetna_duljina);
//}
//
//void Tablica::Inicijaliziraj(size_t pocetna_duljina) {
//    elementi = new int[pocetna_duljina];
//    broj_elemenata = 0;
//    duljina = pocetna_duljina;
//    assert(elementi != nullptr);
//}

// primjer1
//Tablica::Tablica()
//        : elementi{new int[podrazumijevna_pocetna_duljina]},
//          broj_elemenata{0},
//          duljina{podrazumijevna_pocetna_duljina}
//{}
//
//Tablica::Tablica(size_t pocetna_duljina)
//        : elementi{new int[pocetna_duljina]},
//          broj_elemenata{0},
//          duljina{pocetna_duljina}
//{}

void Tablica::PovecajNa(size_t nova_duljina) {
    assert(nova_duljina > duljina);
    int* novi_elementi = new int[nova_duljina];
    for (size_t i = 0;  i < broj_elemenata ; i++) {
        novi_elementi[i] = elementi[i];
    }
    delete[] elementi;
    elementi = novi_elementi;
    duljina = nova_duljina;
}

void Tablica::DodajElement(int novi_element) {
    if (duljina == broj_elemenata) PovecajNa(duljina * 2);
    elementi[broj_elemenata++] = novi_element;
}

void Tablica::BrisiElement(size_t pozicija) {
    assert(pozicija < broj_elemenata);
    for (size_t i = pozicija;  i < broj_elemenata - 1; i++) {
        elementi[i] = elementi[i + 1];
    }
    --broj_elemenata;
}


int main() {
    // 1
//    Tablica t1{};
//    Tablica t2{2};

    // 2
//    Tablica t1{};
//    Tablica t2{};
//    globalna += 53;
//    Tablica t3{};

    // 3
    Tablica t1;
    t1.DodajElement(21);
    Tablica t2{t1};
    t1.DodajElement(54);
    cout << "Tablica 1: " << t1.BrojElemenata() << " elemenata:\n";
    for (int i = 0; i < t1.BrojElemenata(); ++i) {
        cout << t1.Element(i) << endl;
    }
    cout << "Tablica 2: " << t2.BrojElemenata() << " elemenata:\n";
    for (int i = 0; i < t2.BrojElemenata(); ++i) {
        cout << t2.Element(i) << endl;
    }
    return 0;
}