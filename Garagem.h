/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Garagem.h
 * Author: Alex Reis
 *
 * Created on 24 de novembro de 2019, 19:07
 */

#ifndef GARAGEM_H
#define GARAGEM_H

#include <vector>
#include "Carro.h"

class Garagem {
    vector<Carro *> carros;
public:
    Garagem(vector<Carro *> carros);
    ~Garagem();
    void setCarros(vector<Carro *> carros);
};

#endif /* GARAGEM_H */

