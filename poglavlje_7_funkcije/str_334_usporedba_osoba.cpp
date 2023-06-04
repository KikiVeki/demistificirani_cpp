//
// Created by User on 4.6.2023..
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

struct Osoba {
    string ime;
    int dob;
};

int UsporedbaOsoba(const void* o1, const void* o2) {
    const Osoba* p_osoba1 = static_cast<const Osoba*> (o1);
    const Osoba* p_osoba2 = static_cast<const Osoba*> (o2);

    if(p_osoba1->dob != p_osoba2->dob) {
        return p_osoba2->dob - p_osoba1->dob;
    }
    return p_osoba1->ime.compare(p_osoba2->ime);
}

int main() {

    vector<Osoba> osobe{{"Dora", 23}, {"Igor", 45}, {"Maja", 23},
                        {"Darko", 23}, {"Maja", 37}};
    for (const Osoba& o: osobe) {
        cout << o.ime << " " << o.dob << endl;
    }
    qsort(osobe.data(), osobe.size(), sizeof(Osoba), UsporedbaOsoba);
    for (const Osoba& o: osobe) {
        cout << o.ime << " " << o.dob << endl;
    }
    return 0;
}