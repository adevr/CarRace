/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Velocidade.cpp
 * Author: Alex Reis
 * 
 * Created on 21 de novembro de 2019, 21:36
 */

#include "Velocidade.h"

void Velocidade::setVelMax(int vel_max){ Velocidade::vel_max = vel_max; }
void Velocidade::setVelAtual(int vel_atual){ Velocidade::vel_atual = vel_atual; }
int Velocidade::getVelAtual(){ return Velocidade::vel_atual; }
int Velocidade::getVelMax(){ return Velocidade::vel_max; }

int Velocidade::acelerar(int velocidade){
    int somaVelocidades = Velocidade::vel_atual + velocidade;
    Velocidade::setVelAtual(((somaVelocidades) >= Velocidade::vel_max) ? Velocidade::vel_max : somaVelocidades);
    return Velocidade::vel_atual;
}

int Velocidade::travar(int velocidade){
    int subtracaoVelocidades = Velocidade::vel_atual - velocidade;
    Velocidade::setVelAtual(((subtracaoVelocidades) <= 0) ? 0 : subtracaoVelocidades);
    return Velocidade::vel_atual;
}

Velocidade::Velocidade(int vel_max){
    Velocidade::setVelAtual(0);
    Velocidade::setVelMax(vel_max);
}

Velocidade::~Velocidade(){}