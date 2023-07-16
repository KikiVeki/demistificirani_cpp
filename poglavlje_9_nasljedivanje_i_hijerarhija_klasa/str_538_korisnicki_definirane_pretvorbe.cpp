//
// Created by User on 16.7.2023..
//
#include <iostream>
using namespace std;

class Kompleksni{
private:
    double realni, imaginarni;
public:
    Kompleksni(double realni = 0, double imaginarni = 0) :
            realni(realni), imaginarni(imaginarni) {}
};

Kompleksni Korijen1(const Kompleksni& komp1){}
Kompleksni Korijen2(const Kompleksni& komp2){}

int main() {

    Kompleksni kor = Korijen1(12.4);
    Kompleksni kor2 = Korijen1(12);
    return 0;
}
