//
// Created by User on 19.5.2023..
//
//template
#include <iostream>

using namespace std;

int main() {
    // zad 1
    int i = 1;
    int* p = &i;
    i = i + 1;
    cout << i << endl << *p << endl;
    *p = *p + 1;
    cout << i << endl << *p << endl;
    *p = i + 1;
    cout << i << endl << *p << endl;

    // zad 2
    i = 1;
    int j = 10;
    p = &j;
    *p *= *p;
    i = i + j;
    p = &i;
    cout << i << endl << j << endl << *p << endl;

    return 0;
}
