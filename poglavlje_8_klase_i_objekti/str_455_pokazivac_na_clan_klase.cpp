//
// Created by User on 2.7.2023..
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Tocka{
    int x;
    int y;
};

using Niz_tocaka = vector<Tocka>;
Niz_tocaka tocke {{1,2}, {3,4}, {5,6}, {7,8}};

int Najmanji(const Niz_tocaka& tocke, const int Tocka::* koordinata) {
    int min = numeric_limits<int>::max();
    for (const Tocka& t : tocke) {
        if(t.*koordinata < min)
            min = t.*koordinata;
    }
    return min;
}

int Najveci(const Niz_tocaka& tocke, const int Tocka::* koordinata) {
    int max = numeric_limits<int>::min();
    for (const Tocka& t : tocke) {
        if(t.*koordinata > max)
            max = t.*koordinata;
    }
    return max;
}

int main() {

    // primjer 1
    Tocka tocka;
    Tocka* pok_tocka = &tocka;
    int Tocka::* pok_koord = &Tocka::x;
    tocka.*pok_koord = 4;
    pok_koord = &Tocka::y;
    pok_tocka->*pok_koord = 6;
    cout << tocka.x << endl << tocka.y << endl;

    // primjer 2

    cout << "Najmanji x: " << Najmanji(tocke, &Tocka::x) << endl;
    cout << "Najmanji y: " << Najmanji(tocke, &Tocka::y) << endl;
    cout << "Najveci x: " << Najveci(tocke, &Tocka::x) << endl;
    cout << "Najveci y: " << Najveci(tocke, &Tocka::y) << endl;

    return 0;
}
