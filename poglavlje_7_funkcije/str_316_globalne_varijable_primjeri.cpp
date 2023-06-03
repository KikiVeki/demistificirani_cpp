//
// Created by User on 3.6.2023..
//
#include <iostream>

using namespace std;

int globalna;
int a = 10;

int main() {

    // primjer 1
    int lokalna;
    cout << globalna << endl;
    cout << lokalna << endl;

    // primjer 2
    double a = 50;
    cout << a << endl;
    cout << ::a<< endl;
    return 0;
}