/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carro.h
 * Author: Alex Reis
 *
 * Created on 21 de novembro de 2019, 21:28
 */

#ifndef CARRO_H
#define CARRO_H

#include <string>
#include "Bateria.h"
#include "SinalEmergencia.h"
#include "Velocidade.h"


using namespace std;

class Carro {
    string marca, modelo;
    char id[1];
    int dano;
    //Bateria bateria;
    //SinalEmergencia sinal;
    //Velocidade velocidade;

public:
    Carro(string marca, string modelo, int capMax, int capIni, int velMax, int estado);
    ~Carro();
    string getMarca();
private:
    void setMarca(string marca);
    void setModelo(string modelo);
    void setID();
};

#endif /* CARRO_H */

