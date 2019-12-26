/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Corrida.h
 * Author: Alex Reis
 *
 * Created on 24 de novembro de 2019, 20:48
 */

#ifndef CORRIDA_H
#define CORRIDA_H

#include <vector>
#include <string>
#include <iostream>
#include "Piloto.h"
#include "Consola.h"
#include "Pista.h"

using namespace std;

class Corrida {
    bool estado;
    vector<Piloto*> participantes;
    Pista* pista;
public:
    Corrida();
    Corrida(const Corrida& orig);
    virtual ~Corrida();
    
    void toggleCorrida(bool estado);
    bool __comecou();
    void iniciar();
    void correr();
};

#endif /* CORRIDA_H */

