//
// Created by User on 8.6.2023..
//
#include <iostream>

using namespace std;

template<typename Tip>
Tip Kvadrat(Tip x) {
    return x * x;
}
template<typename Tip>
Tip Zbroji(initializer_list<Tip> pribrojnici) {
    Tip rezultat = 0;
    for (Tip pribrojnik : pribrojnici) {
        rezultat += pribrojnik;
    }
    return rezultat;
}

int main() {
    float f = 1.4F;
    int i = 9;
    double d = 3.14159;
    cout << Kvadrat(f) << endl;
    cout << Kvadrat(i) << endl;
    cout << Kvadrat(d) << endl;
    cout << Kvadrat(1.4) << endl;

    cout << Zbroji<int>({}) << endl;
//    cout << Zbroji<int>({3.4,2.5,3}) << endl;
    cout << Zbroji<double>({3.4,2.3,5}) << endl;

    return 0;
}