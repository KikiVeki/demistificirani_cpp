//
// Created by User on 31.5.2023..
//
#include <iostream>

using namespace std;

int DodajSto(int i) {
    i += 100;
    return i;
}

void Zamjena (int& prvi, int& drugi) {
    return swap(prvi, drugi);

}

int main() {

    // pass by value
    int n = 1;
    DodajSto(n);
    cout << "Radio " << n << endl;
    n = DodajSto(n);
    cout << "Radio " << n << endl;

    // pass by reference
    int a = 5;
    int b = 10;
    Zamjena(a, b);
    cout << a << " " << b << endl;
    return 0;
}
