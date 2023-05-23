//
// Created by User on 20.5.2023..
//
#include <iostream>

using namespace std;

int main() {
    const char* neki_tekst = "tri+pet";
    char* pok = const_cast<char *>(neki_tekst);

    while (*pok) {
        ++pok;
    }
    int x = pok - neki_tekst;

    cout << x << endl;
    return 0;
}