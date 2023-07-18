//
// Created by User on 17.7.2023..
//
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

enum TipoviPoruka{
    Pogreska = 0x01,
    Upozoroenje = 0x02,
    Info = 0x04,
    SvePoruke = Pogreska | Upozoroenje | Info
};

class Dnevnik{
public:
    virtual ~Dnevnik(){}
    virtual void Zapisi(const string& tekst, TipoviPoruka tip_poruke = Pogreska) = 0;
};

class OsnovniDnevnik: public Dnevnik{
public:
    OsnovniDnevnik(TipoviPoruka tip) : maska_poruka(tip) {}
    virtual ~OsnovniDnevnik() {}
    void Zapisi(const string& tekst, TipoviPoruka tip_poruke = Pogreska);
protected:
    virtual void Ispljuni(const string& tekst) = 0;
private:
    TipoviPoruka maska_poruka;
    string Formatiraj(const string& tekst, TipoviPoruka tip_poruke);
    string DajVrijeme();
    bool DaLiPrikazati(TipoviPoruka tip_poruke);
};

void OsnovniDnevnik::Zapisi(const std::string &tekst, TipoviPoruka tip_poruke) {
    if (DaLiPrikazati(tip_poruke))
        Ispljuni(Formatiraj(tekst, tip_poruke));
}

string OsnovniDnevnik::Formatiraj(const std::string &tekst, TipoviPoruka tip_poruke) {
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

string OsnovniDnevnik::DajVrijeme() {
    char spremnink[80];
    time_t vrijeme;
    time(&vrijeme);
    tm* lokalno_vrijeme = localtime(&vrijeme);
    strftime(spremnink, 80, "%d.%m.%Y %H:%M:%S ", lokalno_vrijeme);
    return string(spremnink);
}

bool OsnovniDnevnik::DaLiPrikazati(TipoviPoruka tip_poruke) {
    return (maska_poruka & tip_poruke) != 0;
}


class DnevnikNaEkran: public OsnovniDnevnik{
public:
    DnevnikNaEkran(TipoviPoruka maska_za_poruke) : OsnovniDnevnik(maska_za_poruke) {}
    ~DnevnikNaEkran() {}
protected:
    void Ispljuni(const string& poruka) override {
        cerr << poruka << endl;
    }
};

class DnevnikUFajlu: public OsnovniDnevnik{
private:
    ofstream izlazni_tok;
public:
    DnevnikUFajlu(const string& ime_fajle, TipoviPoruka maska_za_poruke) :
            OsnovniDnevnik(maska_za_poruke), izlazni_tok(ime_fajle) {}
    ~DnevnikUFajlu() {izlazni_tok.close();}
protected:
    void Ispljuni(const string& poruka) override {
        izlazni_tok << poruka << endl;
    }
};


class PrazniDnevnik: public Dnevnik{
protected:
    void Zapisi(const string& tekst, TipoviPoruka tip_poruke = Pogreska) override;
};


class ListDnevnika: public Dnevnik{
private:
    vector<Dnevnik*> niz_dnevnika;
public:
    ~ListDnevnika();
    void Zapisi(const string& tekst, TipoviPoruka tip_poruke = Pogreska) override;
    void DodajDnevnik(Dnevnik* dnevnik);
};

ListDnevnika::~ListDnevnika() noexcept {
    for (auto dnevnik : niz_dnevnika) {
        delete dnevnik;
    }
}

void ListDnevnika::DodajDnevnik(Dnevnik *dnevnik) {
    niz_dnevnika.push_back(dnevnik);
}

void ListDnevnika::Zapisi(const std::string &tekst, TipoviPoruka tip_poruke) {
    for (auto dnevnik : niz_dnevnika) {
        dnevnik->Zapisi(tekst, tip_poruke);
    }
}

Dnevnik* pok_dnevnik;

void NekaFunkcija() {
    pok_dnevnik->Zapisi("Usao u NekaFunkcija", Info);
}

int main() {
//    cout << "Ispisi na (e)kran ili u (d)atoteku? ";
//    char ch;
//    cin >> ch;
//    switch (ch) {
//        case 'e':
//            pok_dnevnik = new DnevnikNaEkran(Pogreska);
//            break;
//        case 'd':
//            pok_dnevnik = new DnevnikUFajlu("Moj.log", SvePoruke);
//            break;
//        default:
//            pok_dnevnik = new PrazniDnevnik();
//            break;
//    }

    ListDnevnika* pok_ld = new ListDnevnika();
    pok_ld->DodajDnevnik(new DnevnikUFajlu("Sve.log", SvePoruke));
    pok_ld->DodajDnevnik(new DnevnikUFajlu("Pogreske.log", Pogreska));
    pok_ld->DodajDnevnik(new DnevnikNaEkran(Pogreska));

    pok_dnevnik->Zapisi("Usao sam u main()", Info);
    NekaFunkcija();
    pok_dnevnik->Zapisi("Vratio se u main()", Info);
    delete pok_ld;
    return 0;
}
