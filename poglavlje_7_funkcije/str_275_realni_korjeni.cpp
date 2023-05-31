//
// Created by User on 31.5.2023..
//

#include <iostream>
#include <cmath>

using namespace std;

int RealnihKorjena(double a, double b, double c, double& kor1, double& kor2) {
    double diskriminanta = b * b - 4 * a * c;

    if (diskriminanta < 0)
        return 0;
    if (diskriminanta == 0) {
        kor1 = kor2 = -b / 2 / a;
        return 1;
    }
    kor1 = (-b + sqrt(diskriminanta)) / 2 / a;
    kor2 = (-b - sqrt(diskriminanta)) / 2 / a;
    return 2;
}

int main() {

    double kor1, kor2;
    if (RealnihKorjena(1,3,2, kor1, kor2) > 0) {
        cout << "Prvi korjen: " << kor1 << endl;
        cout << "Drugi korjen: " << kor2 << endl;
    } else cout << "Nema realnih korjena!";
    return 0;
}