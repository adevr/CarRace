//
// Created by Alex Reis on 02/11/2019.
//

#ifndef CARRACE_PILOTO_H
#define CARRACE_PILOTO_H

#include <string>
using namespace std;

class Piloto {
    string nome;
public:
    Piloto(string nome);
    ~Piloto();
private:
    void setNome(string nome);
};


#endif //CARRACE_CARRO_H
