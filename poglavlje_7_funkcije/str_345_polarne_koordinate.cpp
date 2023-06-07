//
// Created by User on 7.6.2023..
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x = -1;
    double y = -1;
    double r = sqrt(x * x + y * y);
    double fi = atan2(x, y);
    cout << "r = " << r << ", fi = " << fi << endl;

    return 0;
}