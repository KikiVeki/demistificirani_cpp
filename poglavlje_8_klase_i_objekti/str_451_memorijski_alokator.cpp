//
// Created by User on 2.7.2023..
//
#include <iostream>
#include <vector>
using namespace std;

class MemorijskiAlokator{
private:
    class Alokacija{
    private:
        void* adresa{nullptr};
        size_t velicina{0};
        string datoteka;
        int linija{0};
    public:
        Alokacija(void* adr, size_t vel, const char* dat, int lin);
        void Ispisi() const;
        void* DajAdresu() const {return adresa;}
    };
    vector<Alokacija> alokacije;
public:
    ~MemorijskiAlokator();
    void Dodaj(void* adr, size_t vel, const char* dat, int lin);
    void Brisi(void* adr);
    void Ispisi() const;
};

MemorijskiAlokator::Alokacija::Alokacija(void *adr, size_t vel, const char *dat, int lin) :
        adresa{adr}, velicina{vel}, datoteka{dat}, linija{lin}
{}

void MemorijskiAlokator::Alokacija::Ispisi() const {
    cout << datoteka << ": Ln " << linija << " = " << velicina;
    cout << " : " << adresa << endl;
}

MemorijskiAlokator::~MemorijskiAlokator() {
    cout << "Neoslobodene alokacije:" << endl;
    Ispisi();
}

void MemorijskiAlokator::Dodaj(void *adr, size_t vel, const char *dat, int lin) {
    alokacije.push_back(Alokacija{adr, vel, dat, lin});
}

void MemorijskiAlokator::Brisi(void *adr) {
    for (auto it = alokacije.begin(); it != alokacije.end(); ++it) {
        if((*it).DajAdresu() == adr) {
            alokacije.erase(it);
            return;
        }
    }
}

void MemorijskiAlokator::Ispisi() const {
    for (const Alokacija& alok : alokacije) {
        alok.Ispisi();
    }
}


int main() {
    return 0;
}
