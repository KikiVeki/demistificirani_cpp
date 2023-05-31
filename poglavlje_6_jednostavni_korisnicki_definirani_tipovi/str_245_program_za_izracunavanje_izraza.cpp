//
// Created by User on 23.5.2023..
//
//template
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


int main() {

    string izraz;
    getline(cin, izraz);

    vector<Unos> unosi;
    size_t pozicija = 0;

    while (pozicija != string::npos) {
        size_t broj_znakova;
        double broj = stod(&izraz[pozicija], &broj_znakova);
        pozicija += broj_znakova;
        Unos unos_broja;
        unos_broja.vrsta = VrstaUnosa::Broj;
        unos_broja.broj = broj;

        unosi.push_back(unos_broja);

        pozicija = izraz.find_first_not_of(' ', pozicija);
        if (pozicija == string::npos) break;

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
                throw::runtime_error("Neispravan operator!");
        }

        unosi.push_back(unos_operatora);
        pozicija = izraz.find_first_not_of(' ', ++pozicija);
    }

    vector<Operator> operatori;
    vector<double> operandi;

    for (Unos unos : unosi) {
        if(unos.vrsta == VrstaUnosa::Broj) operandi.push_back(unos.broj);
        else if (unos.vrsta == VrstaUnosa::Operator) {
            Operator zadnji_operator = unos.operacija;
            while (!operatori.empty() && hijerarhija[operatori.back()] >= hijerarhija[zadnji_operator]) {
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
            operatori.push_back(zadnji_operator);
        }
    }

    while (!operatori.empty()) {
        Operator op = operatori.back();
        operatori.pop_back();
        double desni = operandi.back();
        operandi.pop_back();
        double lijevi = operandi.back();
        operandi.pop_back();

        switch (op) {
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

    cout << operandi[0] << endl;
    return 0;
}
