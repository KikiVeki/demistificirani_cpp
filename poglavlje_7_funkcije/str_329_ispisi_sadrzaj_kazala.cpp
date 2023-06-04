//
// Created by User on 4.6.2023..
//
#include <iostream>
#include <filesystem>
#include <iomanip>

using namespace std::filesystem;
using namespace std;

void IspisiSadrzajKazala(const path& kazalo, int dubina = 0) {
    using dirIter = directory_iterator;
    for(dirIter iter(kazalo); iter != dirIter(); ++iter) {
        if(is_directory(iter->path())) {
            cout << setw(dubina) <<"kazalo:   " << iter->path() << endl;
            IspisiSadrzajKazala(*iter, dubina + 2);
        }
        if(is_regular_file(iter->path())) {
            cout << "datoteka:   " << iter->path().filename() << endl;
        }
    }
}

int main() {

//    IspisiSadrzajKazala(R"(c:\Users\User\CLionProjects\demistificirani_cpp)");
    IspisiSadrzajKazala(R"(D:\Aplikacije)");
    return 0;
}