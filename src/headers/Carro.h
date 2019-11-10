//
// Created by Alex Reis on 02/11/2019.
//

#ifndef RACESIMULATOR_CARRO_H
#define RACESIMULATOR_CARRO_H

#include <string>
#include "./Piloto.h"
#include "./Bateria.h"
#include "./SinalEmergencia.h"
#include "./Velocidade.h"


using namespace std;

class Carro {
    string marca, modelo;
    char id[1];
    int dano;
    int velocidade;
    Piloto piloto;
    Bateria bateria;
    SinalEmergencia sinal;
    Velocidade velocidade;

public:
    Carro(string marca, string modelo, int capMax, int capIni, int velMax, int estado) ;
    ~Carro();
private:
    void setMarca(string marca);
    void setModelo(string modelo);
    void setID();
};


#endif //RACESIMULATOR_CARRO_H
