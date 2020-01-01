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

#include "Piloto.h"
#include "Corrida.h"
#include <iostream>
#include <vector>
#include <string>



using namespace std;

class Pista {
    int comprimento, capacidade;
    Corrida* corrida;
    vector <Piloto*> participantes;
public:
    Pista(int comprimento, int capacidade, vector <Piloto*>participantes);
    void setParticipante(Piloto* piloto);
    vector < Piloto*> getParticipantes();
    Corrida* getCorrida() const;
    ~Pista();
    int getComprimento() const;
    
private:

};

#endif /* PISTA_H */

