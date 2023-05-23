//
// Created by User on 20.5.2023..
//

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {

    const string vrijednosti[]{"cener", "decec", "dama", "kral", "as"};
    const string boje[]{"herc", "tikva", "zelje", "zir"};
    const int broj_djeljenja = 6;
    const int broj_vrijednosti{sizeof(vrijednosti)  / sizeof(string)};
    const int broj_boja{sizeof(boje)  / sizeof(string)};

    string* karte_kod_igraca[broj_vrijednosti][broj_boja];
    using Karta = pair<int, int>;
    vector<Karta> preostale_karte;

    for (int vr = 0; vr < broj_vrijednosti; ++vr) {
        for (int boja = 0; boja <broj_boja; ++boja) {
            karte_kod_igraca[vr][boja] = nullptr;
            preostale_karte.push_back(Karta{vr, boja});
        }
    }

    vector<string> igraci{"Ivan", "Goran"};
    auto klica = system_clock::now().time_since_epoch().count();
    default_random_engine generator(static_cast<unsigned> (klica));

    cout << "Pocetno dijeljenje: " << endl;
    for (int krug = 0; krug < broj_djeljenja; ++krug) {
        for (auto &igrac : igraci) {
            int n_max = preostale_karte.size() - 1;
            uniform_int_distribution<int> raspodjela(0, n_max);
            int slucajni = raspodjela(generator);

            Karta karta = preostale_karte[slucajni];
            int vr = karta.first;
            int boja = karta.second;
            karte_kod_igraca[vr][boja] = &igrac;
            preostale_karte.erase(preostale_karte.begin() + slucajni);

            cout << igrac << " je dobio " << vrijednosti[vr] << " " << boje[boja] << endl;
        }
    }

    cout << "Karte su podijeljenje: " << endl;
    for (int vr = 0; vr < broj_vrijednosti; ++vr) {
        for (int boja = 0; boja < broj_boja; ++boja) {
            cout << vrijednosti[vr] << " " << boje[boja];
            if (karte_kod_igraca[vr][boja] == nullptr) {
                cout << " nije podijeljena" << endl;
            } else {
                cout << " ima " << *karte_kod_igraca[vr][boja] << endl;
            }
        }
    }

    return 0;
}