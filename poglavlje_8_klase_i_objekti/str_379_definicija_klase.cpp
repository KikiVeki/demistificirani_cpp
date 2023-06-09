//
// Created by User on 9.6.2023..
//
#include <iostream>

using namespace std;

//primjer str 381
class Racunalo {
public:
    int kBMemorije;
    int broj_diskova;
    int megahertza;
};

int main() {

    Racunalo moj_kucni_cray;
    Racunalo& ref_racunalo = moj_kucni_cray;
    moj_kucni_cray.kBMemorije = 64;
    ref_racunalo.broj_diskova = 5;
    Racunalo* pok_racunalo = &moj_kucni_cray;
    pok_racunalo->megahertza = 16;
    return 0;
}