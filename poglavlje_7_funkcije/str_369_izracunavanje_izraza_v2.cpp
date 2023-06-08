//
// Created by User on 8.6.2023..
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

enum class VrstaUnosa {Broj, Operator, LijevaZagrada, DesnaZagrada, Funkcija};
enum class Operator {Zbroji, Oduzmi, Pomnozi, Podijeli};

struct Unos{
    VrstaUnosa vrsta;
    union {
        double broj;
        Operator operacija;
        const char* funkcija;
    };
};

union SadrzajUnosa{
    double broj;
    Operator operacija;
    const char* funkcija;
};

map<Operator, int> hijerarhija{
        {Operator::Zbroji, 1},
        {Operator::Oduzmi, 1},
        {Operator::Pomnozi, 2},
        {Operator::Podijeli, 2},
};

void UnosLijevihZagrada(const string& izraz, size_t& pozicija,
        vector<Unos>& unosi, int& broj_otvorenih_zagrada);
bool UnosDesnihZagrada(const string& izraz, size_t& pozicija,
                       vector<Unos>& unosi, int& broj_otvorenih_zagrada);
void UnosBroja(const string& izraz, size_t& pozicija,
               vector<Unos>& unosi);
void UnosOperatora(const string& izraz, size_t& pozicija,
                   vector<Unos>& unosi);
void IzracunajOperaciju(vector<Operator>& operatori, vector<double>& operandi);
double IzracunajIzraz(const vector<Unos>& unosi);

int main() {
    string izraz;
    getline(cin, izraz);
    try {
        vector<Unos> unosi;
        size_t pozicija = 0;
        int broj_otovrenih_zagrada = 0;
        pozicija = izraz.find_first_not_of(' ', pozicija);

        while (pozicija != string::npos) {
            UnosLijevihZagrada(izraz, pozicija, unosi, broj_otovrenih_zagrada);
            UnosBroja(izraz, pozicija, unosi);
            while ((pozicija != string::npos) && (izraz.at(pozicija) != ')')) {
                UnosOperatora(izraz, pozicija, unosi);
                UnosLijevihZagrada(izraz, pozicija, unosi, broj_otovrenih_zagrada);
                UnosBroja(izraz, pozicija, unosi);
            }
            if (UnosDesnihZagrada(izraz, pozicija, unosi, broj_otovrenih_zagrada) && (pozicija != string::npos)) {
                UnosOperatora(izraz, pozicija, unosi);
            }
        }
        if (broj_otovrenih_zagrada > 0) {
            throw runtime_error("Visak lijevih zagrada");
        }
        cout << IzracunajIzraz(unosi) << endl;
    }
    catch (invalid_argument) {
        cerr << "Neispravni operand" << endl;
    }
    catch (runtime_error iznimka) {
        cerr << iznimka.what() << endl;
    }
    return 0;
}

void UnosLijevihZagrada(const string& izraz, size_t& pozicija,
                        vector<Unos>& unosi, int& broj_otvorenih_zagrada) {
    while (izraz.at(pozicija) == '(') {
        Unos unos_lijeve_zagrade;
        unos_lijeve_zagrade.vrsta = VrstaUnosa::LijevaZagrada;
        unosi.push_back(unos_lijeve_zagrade);
        ++broj_otvorenih_zagrada;
        pozicija = izraz.find_first_not_of(' ', ++pozicija);
    }
}

bool UnosDesnihZagrada(const string& izraz, size_t& pozicija,
                       vector<Unos>& unosi, int& broj_otvorenih_zagrada){
    if(pozicija == string::npos || izraz.at(pozicija) != ')') return false;
    while (pozicija != string::npos && izraz.at(pozicija) == ')') {
        Unos unos_desne_zagrade;
        unos_desne_zagrade.vrsta = VrstaUnosa::DesnaZagrada;
        unosi.push_back(unos_desne_zagrade);
        --broj_otvorenih_zagrada;
        if(broj_otvorenih_zagrada < 0) {
            string poruka("Desna zagrada viska na poziciji ");
            poruka.append(to_string(pozicija));
            throw runtime_error(poruka);
        }
        pozicija = izraz.find_first_not_of(' ', ++pozicija);
    }
    return true;
}

void UnosBroja(const string& izraz, size_t& pozicija,
               vector<Unos>& unosi){
    size_t broj_znakova;
    double broj = stod(&izraz[pozicija], &broj_znakova);
    Unos unos_broja;
    unos_broja.vrsta = VrstaUnosa::Broj;
    unos_broja.broj = broj;
    unosi.push_back(unos_broja);
    pozicija = izraz.find_first_not_of(' ', pozicija + broj_znakova);
}

void UnosOperatora(const string& izraz, size_t& pozicija,
                   vector<Unos>& unosi){
    char operacija = izraz.at(pozicija);
    Unos unos_operatora;
    unos_operatora.vrsta = VrstaUnosa::Operator;
    switch (operacija) {
        case '+':
            unos_operatora.operacija = Operator::Zbroji;
            break;
        case '-':
            unos_operatora.operacija = Operator::Oduzmi;
            break;
        case '*':
            unos_operatora.operacija = Operator::Pomnozi;
            break;
        case '/':
            unos_operatora.operacija = Operator::Podijeli;
            break;
        default:
            throw runtime_error{"Neispravni operator"};
    }
    unosi.push_back(unos_operatora);
    pozicija = izraz.find_first_not_of(' ', ++pozicija);
}

void IzracunajOperaciju(vector<Operator>& operatori, vector<double>& operandi) {
    Operator prethodni_operator = operatori.back();
    operatori.pop_back();
    double desni = operandi.back();
    operandi.pop_back();
    double lijevi = operandi.back();
    operandi.pop_back();
    switch (prethodni_operator) {
        case Operator::Zbroji:
            operandi.push_back(lijevi + desni);
            break;
        case Operator::Oduzmi:
            operandi.push_back(lijevi - desni);
            break;
        case Operator::Pomnozi:
            operandi.push_back(lijevi * desni);
            break;
        case Operator::Podijeli:
            operandi.push_back(lijevi / desni);
            break;
    }
}

double IzracunajIzraz(const vector<Unos>& unosi){
    vector<Operator> operatori;
    vector<double> operandi;
    for (vector<Unos>::const_iterator it = unosi.begin(); it != unosi.end(); ++it) {
        Unos unos = *it;
        if(unos.vrsta == VrstaUnosa::LijevaZagrada) {
            vector<Unos>::const_iterator pocetak_zagrade = it;
            int otvorene_zagrade = 1;
            while (otvorene_zagrade > 0) {
                ++it;
                if (it->vrsta == VrstaUnosa::LijevaZagrada)
                    ++otvorene_zagrade;
                if (it->vrsta == VrstaUnosa::DesnaZagrada)
                    --otvorene_zagrade;
            }
            vector<Unos> unutar_zagrade(pocetak_zagrade + 1, it);
            double rezultat_zagrade = IzracunajIzraz(unutar_zagrade);
            operandi.push_back(rezultat_zagrade);
        }
        else if (unos.vrsta == VrstaUnosa::){

        }
    }
}