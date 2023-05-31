//
// Created by User on 31.5.2023..
//
//template
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned char a = 0x25;
    unsigned char b = ~a;
    cout << hex << static_cast<int>(a) << endl;
//    cout << static_cast<int>(a) << endl;
    cout << static_cast<int> (b) << endl;

    int aa = 0b00100101;
    int maska = 0b00001111;
    cout << bitset<8> (a & maska) << endl;

    aa = 0x0025;
    maska = 0x000f;
    cout << bitset<8> (a | maska) << " " << hex << (a | maska) << endl;

    cout <<  hex << (aa ^ maska) << endl;
    cout <<  hex << (aa ^ maska ^ maska) << endl;

    aa = 20;
    cout << dec << (aa << 1)<< endl;
    cout << (aa >> 2)<< endl;

    enum {Baud110 = 0, Baud150, Baud300, Baud600, Baud1200, Baud2400, Baud4800, Baud9600};
    enum {Bitova7 = 0x00, Bitova8 = 0x08};
    enum {StopB1 = 0x10, StopB2 = 0x20};
    enum {ParitetNjet = 0x00, ParitetNeparni = 0x40, ParitetParni = 0x80};

    unsigned int ser_com {Baud1200 | Bitova8 | StopB2| ParitetNjet};
    unsigned int brzina {ser_com | 0x07};
    bool je_li_8_bita = ser_com | 0x08;
    unsigned int broj_stop_bitova {ser_com | 0x30};
    broj_stop_bitova = broj_stop_bitova >> 4;

    // str 257
    struct Prekid {
        unsigned short dozvoljen : 1;
        unsigned short prioritet : 3;
        unsigned short maska : 2;
    };

    cout << dec << sizeof (Prekid) << endl;

    Prekid prekid{0};
    prekid.dozvoljen = 1;
    if (prekid.prioritet == 0) prekid.maska = 2;
//    if (prekid.prioritet == 2) prekid.maska = 1;

    cout << prekid.dozvoljen << endl;
    cout << prekid.prioritet << endl;
    cout << prekid.maska << endl;

    return 0;
}

