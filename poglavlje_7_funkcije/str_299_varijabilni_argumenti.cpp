//
// Created by User on 3.6.2023..
//
#include <iostream>
#include <cstdarg>

using namespace std;

int IspisiFormatirano(const char* format, ...) {
    va_list v_lista;
    va_start(v_lista, format);
    int i = 0;
    while(format[i] != 0) {
        if(format[i] == '%') {
            ++i;
            switch (format[i]) {
                case 'd':
                case 'i':
                    {
                    int br = va_arg(v_lista, int);
                    cout << br;
                    }
                    break;
                case 's':
                {
                    char* zn_niz = va_arg(v_lista, char*);
                    cout << zn_niz;
                }
                    break;
                case 'c':
                {
                    char zn = va_arg(v_lista, int);
                    cout << zn;
                }
                    break;
                case '%':
                    cout << '%';
                    break;
                default:
                    cout << endl;
                    cerr << "\n Nepodrzani format podatka: %" << format[i] << endl;
                    va_end(v_lista);
                    return 0;
            }
        } else cout << format[i];
        ++i;
    }
    va_end(v_lista);
    return 1;
}

int main() {
    IspisiFormatirano("Dalmatinac i %d %s%c", 101, "dalmatine", 'r');
    return 0;
}