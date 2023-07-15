//
// Created by User on 15.7.2023..
//
#include <iostream>
using namespace std;

class Osnovna{
public:
    int i;
    void Var() {cout << "Osnovna::i " << i << endl;}
};

class Izvedena: public Osnovna{
public:
    int i;
    void Int() {cout << "Izvedena::i " << i << endl;}
};


// primjer str 508
//class A{
//public:
//    void Opis() {cout << "Klasa A!" <<endl;}
//};
//
//class B: public A{
//public:
//    void Opis() {
//        cout << "Klasa b!" <<endl;
//        A::Opis();
//    }
//};

int main() {

    Izvedena izv{};
    izv.i = 9;
    izv.Osnovna::i = 20;
    izv.Var();
    izv.Int();
    return 0;
}
