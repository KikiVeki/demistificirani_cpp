//
// Created by User on 8.6.2023..
//
#include <iostream>

using namespace std;

//template<typename T1, typename T2>
//decltype(auto) Veci(const T1& a, const T2& b) {
//    return a > b ? a : b;
//}

template<typename T1, typename T2>
decltype(auto) Veci(T1& a, T2& b) {
    return a > b ? a : b;
}

int main() {

    // primjer1
    int c = 6;
    int& refc = c;
    auto ac = refc;
    decltype(auto) dac = refc;
    refc++;

    cout << ac << endl;
    cout << dac << endl;

    // primjer2
    int a = 5;
    int b = 7;
    int& ab = Veci(a, b);
    ++ab;
    double cc = 10;
    int& acc = Veci(a,cc);
    ++ac;

    cout << ab << endl;
    cout << acc << endl;


    return 0;
}