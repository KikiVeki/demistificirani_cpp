//
// Created by User on 18.5.2023..
//
//template
#include <iostream>
#include <vector>

using namespace std;

int main() {

    using VecInt = vector<int>;
    VecInt vi{1, 23, 34, 13, 17, 22};
    int broj_parnih = 0;

    for(int & it : vi) {
        if(it % 2 == 0) {
            ++broj_parnih;
        }
    }

    for(auto it = vi.begin(); it != vi.end(); ++it) {
        if(*it % 2 == 0) {
            ++broj_parnih;
        }
    }

    cout << broj_parnih << endl;
    return 0;
}
