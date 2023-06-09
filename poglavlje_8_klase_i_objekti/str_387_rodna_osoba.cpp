//
// Created by User on 9.6.2023..
//
#include <iostream>

using namespace std;

class RodnaOsoba{
private:
    string ime;
    RodnaOsoba* otac{nullptr};

public:
    RodnaOsoba(const string& ime) : ime(ime){}
    void  BitCuOtac(RodnaOsoba* osoba) {
        osoba->otac = this;
    }
};

int main() {

    RodnaOsoba japa{"Francek"};
    RodnaOsoba sinek{"Stefek"};
    japa.BitCuOtac(&sinek);
    return 0;
}