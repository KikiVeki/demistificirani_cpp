//
// Created by User on 3.6.2023..
//
#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

int Zbroji (initializer_list<int> pribrojnici) {
    int rezultat = 0;
    for (auto sumand : pribrojnici) {
        rezultat += sumand;
    }
    return rezultat;
}

int main() {

    cout << Zbroji({1,5,43,5}) << endl;
//    vector<int> a{3,4,5};
//    cout << Zbroji(a);
    return 0;
}