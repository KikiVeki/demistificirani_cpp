//
// Created by User on 11.6.2023..
//
#include <iostream>
using namespace std;

class Kompleksni{
private:
    double realni{0.0}, imaginarni{0.0};
public:
    Kompleksni(double realni_dio, double imaginarni_dio)
            : realni(realni_dio), imaginarni(imaginarni_dio) {}
    double DajRealni() const noexcept{return realni;}
    double DajImagninarni() const noexcept{return imaginarni;}
    void Postavi(double realni_dio, double imaginarni_dio) {
        realni = realni_dio;
        imaginarni = imaginarni_dio;
    }
};

Kompleksni a{10, 20};

Kompleksni Sumiraj(Kompleksni& ref) {
    static Kompleksni suma{0, 0};
    suma.Postavi(suma.DajRealni() + ref.DajRealni(), suma.DajImagninarni() + ref.DajImagninarni());
    return suma;
}

int main() {
    Kompleksni zbroja = Sumiraj(a);
    return 0;
}
