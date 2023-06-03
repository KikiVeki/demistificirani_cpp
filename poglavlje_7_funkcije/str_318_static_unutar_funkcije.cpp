//
// Created by User on 3.6.2023..
//
#include <iostream>
#include <ctime>

using namespace std;

void VoliMeNeVoli()
{
    static bool voliMe = false;
    voliMe = !voliMe;
    if (voliMe) cout << "Voli me!" << endl;
    else cout << "Ne voli!" << endl;
}

int main() {
    int i = time(0) % 10 + 1;
    while (i--) {
        VoliMeNeVoli();
    }
    return 0;
}