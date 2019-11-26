/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Garagem.cpp
 * Author: Alex Reis
 * 
 * Created on 24 de novembro de 2019, 19:07
 */

#include "Garagem.h"

void Garagem::setCarros(vector<Carro*> carros){
    Garagem::carros = carros;
}

Garagem::Garagem(vector<Carro*> carros) {
    setCarros(carros);
}

Garagem::~Garagem() {
}

