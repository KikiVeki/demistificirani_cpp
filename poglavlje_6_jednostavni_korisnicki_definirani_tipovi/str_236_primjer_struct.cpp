//
// Created by User on 23.5.2023..
//
//template
#include <iostream>

using namespace std;

int main() {

    // primjer1
    struct Tocka{
        double x;
        double y;
    };

    struct Datum{
        int dan;
        int mjesec;
        int godina;
    };

    struct Osoba{
        string ime;
        string prezime;
        Datum datum_rodenja;
    };


    // primjer2
//    Tocka t1;
    Tocka t2;

    Tocka t1{3.2, 5};
//    Osoba a{0, "Peric", Datum{1,2,3}};


    // primjer3
    Tocka t3{1, -3};
    t3.x = 4;

    cout << "(" << t3.x << " , " << t3.y << ")" << endl;

    // primjer4
    Tocka t4{4, 12};
    Tocka* tpok4 = &t4;

    cout << "(" << (*tpok4).x << " , " << (*tpok4).y << ")" << endl;
    cout << "(" << tpok4->x << " , " << tpok4->y << ")" << endl;


    // primjer5
    Osoba klimatolog{"Milutin", "Milankovic" , {28, 5, 1879}};
    int god_rodenja = klimatolog.datum_rodenja.godina;

    Osoba* pok_klimatolog = &klimatolog;
    god_rodenja = pok_klimatolog->datum_rodenja.godina;


    // primjer6
    struct RodnaOsoba {
        string ime;
        RodnaOsoba* otac{nullptr};
        RodnaOsoba* majka{nullptr};
    };

    RodnaOsoba kajbumscak{"Jozef"};
    RodnaOsoba babica{"Bara"};
    babica.otac = &kajbumscak;
    RodnaOsoba jopa{"Alojzije"};
    jopa.majka = &babica;
    RodnaOsoba sinek{"Stef"};
    sinek.otac = &jopa;

    cout << sinek.otac->majka->ime << endl;
    cout << sinek.otac->majka->otac->ime << endl;

    // primjer7: ugnjezdena struktura
    struct Osoba2 {
        string ime;
        string prezime;
        struct Datum {
            int dan;
            int mjesec;
            int godina;
        } datum_rodenja;
    };

    Osoba2::Datum neki_datum{1,2, 3};

    return 0;
}
