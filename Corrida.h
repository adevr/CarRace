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
#include "drawer.h"

using namespace std;
using namespace drawer;

class Corrida {
    bool estado;
    vector<Piloto*>participantes;
    vector<string> classificacaoCorrida;
public:
    Corrida(vector < Piloto*>participantes);
    virtual ~Corrida();
    void setParticipante(Piloto* piloto);
    void toggleCorrida(bool estado);
    bool __comecou();
    void iniciar();
    bool correr(int tempo, int tamanhoPista);
private:
    bool finalizaCorrida(vector<Piloto*> participantes);
};

#endif /* CORRIDA_H */

