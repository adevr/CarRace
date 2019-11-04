//
// Created by Alex Reis on 02/11/2019.
//

#ifndef CARRACE_CARRO_H
#define CARRACE_CARRO_H

#include <string>
#include "./Piloto.h"
#include "./Bateria.h"

using namespace std;

class Carro {
    string marca, modelo;
    char id[1];
    int dano;
    int velocidade;
    Piloto piloto;
    Bateria bateria;
public:
    Carro(string marca, string modelo = "Modelo Base");
    ~Carro();
private:
    void setMarca(string marca);
    void setModelo(string modelo);
    void setID();
};


#endif //CARRACE_CARRO_H
