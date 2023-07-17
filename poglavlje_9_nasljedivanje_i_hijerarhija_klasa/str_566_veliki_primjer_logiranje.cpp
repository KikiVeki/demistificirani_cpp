//
// Created by User on 17.7.2023..
//
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum TipoviPoruka{
    Pogreska = 0x01,
    Upozoroenje = 0x02,
    Info = 0x04,
    SvePoruke = Pogreska | Upozoroenje | Info
};

class DnevnikNaEkran{
public:
    DnevnikNaEkran(TipoviPoruka tip) : maska_poruka(tip) {}
    void Zapisi(const string& tekst, TipoviPoruka tip_poruke = Pogreska);
private:
    TipoviPoruka maska_poruka;
    string Formatiraj(const string& tekst, TipoviPoruka tip_poruke);
    string DajVrijeme();
    bool DaLiPrikazati(TipoviPoruka tip_poruke);
};

void DnevnikNaEkran::Zapisi(const std::string &tekst, TipoviPoruka tip_poruke) {
    if (DaLiPrikazati(tip_poruke))
        cerr << Formatiraj(tekst, tip_poruke) << endl;
}

string DnevnikNaEkran::Formatiraj(const std::string &tekst, TipoviPoruka tip_poruke) {
    string poruka(DajVrijeme());
    switch (tip_poruke) {
        case Pogreska:
            poruka.append("POGRESKA:     ");
            break;
        case Upozoroenje:
            poruka.append("UPOZORENJE:   ");
            break;
        case Info:
            poruka.append("INFORMACIJA:  ");
            break;
    }
    poruka.append(tekst);
    return poruka;
}

string DnevnikNaEkran::DajVrijeme() {
    char spremnink[80];
    time_t vrijeme;
    time(&vrijeme);
    tm* lokalno_vrijeme = localtime(&vrijeme);
    strftime(spremnink, 80, "%d.%m.%Y %H:%M:%S ", lokalno_vrijeme);
    return string(spremnink);
}


bool DnevnikNaEkran::DaLiPrikazati(TipoviPoruka tip_poruke) {
    return (maska_poruka & tip_poruke) != 0;
}


DnevnikNaEkran* pok_dnevnik;

void NekaFunkcija() {
    pok_dnevnik->Zapisi("Usao u NekaFunkcija", Info);
}

int main() {
    pok_dnevnik = new DnevnikNaEkran(SvePoruke);
    pok_dnevnik->Zapisi("Usao sam u main()", Info);
    NekaFunkcija();
    pok_dnevnik->Zapisi("Vratio se u main()", Info);
    delete pok_dnevnik;
    return 0;
}
