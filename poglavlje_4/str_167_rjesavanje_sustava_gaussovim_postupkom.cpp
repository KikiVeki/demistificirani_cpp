//
// Created by User on 16.5.2023..
//

//template
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int nmax = 20;
    double a[nmax][nmax + 1];
    ifstream ulazni_tok("C:\\Users\\User\\CLionProjects\\demistificirani_cpp\\poglavlje_4\\koeficjenti.txt");

    if(!ulazni_tok) {
        cerr << "Ne mogu otvoriti traženu datoteku!" << endl;
        return 1;
    }

    int n;
    ulazni_tok >> n;

    if (n > nmax) {
        cerr << "Sustav jednadbi prevelik!" << endl;
        return 2;
    }

    for (int r = 0; r < n; ++r) {
        for (int s = 0; s <= n; ++s) {
            ulazni_tok >> a[r][s];
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int s = r + 1; s <= n; ++s) {
            a[r][s] /= a[r][r];
        }
        for (int rr = r + 1; rr < n; ++rr) {
            for (int ss = r + 1; ss <= n; ++ss) {
                a[rr][ss] -= a[rr][r] * a[r][ss];
            }
        }
    }

    for (int r = n - 1; r >= 0; --r) {
        for (int s = n - 1; s > r; --s) {
            a[r][n] -= a[r][s] * a[s][n];
        }
    }

    for (int r = 0; r < n; ++r) {
        cout << "x" << (r + 1) << " = " << a[r][n] << endl;
    }

    return 0;
}
