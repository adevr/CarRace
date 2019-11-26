/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Corrida.cpp
 * Author: Alex Reis
 * 
 * Created on 24 de novembro de 2019, 20:48
 */

#include "Corrida.h"

void Corrida::toggleCorrida(bool estado){ 
    /*
     * falta verificar se existem pelo menos
     * 2 carros na pista
     * criar funçao no carro? ou corrida?
     */
    Corrida::estado = estado; 
}
bool Corrida::__comecou(){ return Corrida::estado; }

Corrida::Corrida() {
}

Corrida::Corrida(const Corrida& orig) {
}

Corrida::~Corrida() {
}

