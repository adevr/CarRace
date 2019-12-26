/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pista.h
 * Author: Alex Reis
 *
 * Created on 24 de novembro de 2019, 19:50
 */

#ifndef PISTA_H
#define PISTA_H

#include <iostream>
#include <vector>
#include <string>

#include "Piloto.h"
#include "Corrida.h"

using namespace std;

class Pista {
    int comprimento, capacidade;
    Corrida* corrida;
    vector <Piloto*> participantes;
public:
    Pista(int comprimento, int capacidade, vector <Piloto*>participantes);
    void setParticipante(Piloto* piloto);

    Corrida* getCorrida() const;
    virtual ~Pista();
    
private:

};

#endif /* PISTA_H */

