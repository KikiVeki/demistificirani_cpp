//
// Created by User on 3.6.2023..
//
#include <iostream>

using namespace std;

long long Faktorijel(int, int = 1);

int main() {

    int p,r;
    cout << "p= ";
    cin >> p;
    cout << "r= ";
    cin >> r;
    cout << Faktorijel(p, p-r+1) / Faktorijel(r) << endl;

    return 0;
}

long long Faktorijel(int n, int stoj_broj) {
    long long umnozak = stoj_broj;
    while (++stoj_broj <= n) {
        umnozak *= stoj_broj;
    }
    return umnozak;
}