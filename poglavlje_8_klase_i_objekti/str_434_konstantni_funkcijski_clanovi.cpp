//
// Created by User on 11.6.2023..
//
#include <iostream>
using namespace std;

class Vektor{
private:
    double ax{0.0}, ay{0.0};
//    int broji;
    mutable int broji;
public:
    Vektor() = default;
    Vektor(double x, double y) : ax(x), ay(y) {}
    void PostaviXY(double x, double y) {ax = x; ay = y;}
    void PostaviXY(double, double) const;
//    double DajX() const noexcept {return ax;}
//    double DajY() const noexcept {return ay;}
    double DajX() const noexcept;
    double DajY() const noexcept;
    Vektor Pribroji(const Vektor& v) const {
        return Vektor(ax + v.DajX(), ay + v.DajY());
    }
};

void Vektor::PostaviXY(double, double) const {
    cout << "Promjena konstantnog objekta!" << endl;
}

//double Vektor::DajX() const noexcept {
//    ++(const_cast<int&>(broji));
//    return ax;
//}
//
//double Vektor::DajY() const noexcept {
//    ++(const_cast<int&>(broji));
//    return ay;
//}

// ako se broji proglasi mutable
double Vektor::DajX() const noexcept {
    broji++;
    return ax;
}

double Vektor::DajY() const noexcept {
    broji++;
    return ay;
}

int main() {
    const Vektor v{12, 3};
    cout << "X: " << v.DajX() << endl;
    cout << "Y: " << v.DajY() << endl;
    v.PostaviXY(4, 5);
    return 0;
}
