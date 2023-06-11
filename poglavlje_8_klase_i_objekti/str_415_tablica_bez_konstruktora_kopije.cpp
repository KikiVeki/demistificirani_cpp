//
// Created by User on 9.6.2023..
//
#include <iostream>
using namespace std;

class TablicaSeNeDaKopirati{
    // novo
public:
    TablicaSeNeDaKopirati() = default;
    TablicaSeNeDaKopirati(const TablicaSeNeDaKopirati&) = delete;
    TablicaSeNeDaKopirati& operator=(const TablicaSeNeDaKopirati&) = delete;
    // staro
//private:
//    TablicaSeNeDaKopirati(const TablicaSeNeDaKopirati&);
//    TablicaSeNeDaKopirati& operator=(const TablicaSeNeDaKopirati&);
};

int main() {
    return 0;
}
