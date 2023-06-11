//
// Created by User on 11.6.2023..
//
#include <iostream>
using namespace std;

class PrimjerVolatile {
public:
    void F1();
    void F2() volatile;
};

int main() {
    volatile PrimjerVolatile a;
//    a.F1();
    a.F2();
    return 0;
}
