/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pista.cpp
 * Author: Alex Reis
 * 
 * Created on 24 de novembro de 2019, 19:50
 */

#include "Pista.h"

Pista::Pista(int comprimento, int capacidade, vector < Piloto*>participantes) {
    Pista::comprimento = comprimento;
    Pista::capacidade = capacidade;
    Pista::corrida = new Corrida(Pista::participantes);
}


Corrida* Pista::getCorrida() const
{
    return Pista::corrida;
}

void Pista::setParticipante(Piloto* piloto)
{
    if (piloto != nullptr) {
        participantes.push_back(piloto);
        corrida->setParticipante(piloto);
    }
    else cout << "Piloto Invalido";
}

Pista::~Pista() 
{
}

vector < Piloto*> Pista::getParticipantes()
{
    return Pista::participantes;
}