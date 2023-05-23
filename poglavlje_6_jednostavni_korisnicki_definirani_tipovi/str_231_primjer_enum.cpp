//
// Created by User on 23.5.2023..
//
//template
#include <iostream>

using namespace std;

enum class Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
int main() {

    // primjer1
    Dani hvala_bogu_danas_je{Dani::Petak};
    Dani zakaj_ja_ne_volim{Dani::Ponedjeljak};

    cout << static_cast<int> (hvala_bogu_danas_je) << endl;

    enum class Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

    // primjer2
    Dani zec_uvijek_dolazi_u{Dani::Nedjelja};
    cout << static_cast<int> (zec_uvijek_dolazi_u) << endl;

    // primjer3
    enum class Likovi{
        Kruznica = 0,
        Trokut = 3,
        Cetverokut = 4,
        Kvadrat = 4,
        Peterokut,
        Sedmerokut = Cetverokut + 3
    };

    cout << static_cast<int> (Likovi::Kruznica) << endl;
    cout << static_cast<int> (Likovi::Kvadrat) << endl;
    cout << static_cast<int> (Likovi::Peterokut) << endl;
    cout << static_cast<int> (Likovi::Sedmerokut) << endl;
    cout << static_cast<int> (Likovi::Trokut) << endl;

    // primjer 4
    Dani danas = Dani::Petak;
    if(danas == Dani::Petak){
        cout << "Danas je petak!" << endl;
    }

    // primjer5
    enum struct PrometniZnakovi {Krug, Osmerokut, Trokut, Romb};


    return 0;
}
