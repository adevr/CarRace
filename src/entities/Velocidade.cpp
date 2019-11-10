//
// Created by Alex Reis on 08/11/2019.
//

#include "../headers/Velocidade.h"

void Velocidade::setVelMax(int vel_max){ Velocidade::vel_max = vel_max; }
void Velocidade::setVelAtual(int vel_atual){ Velocidade::vel_atual = vel_atual; }
int Velocidade::getVelAtual(){ return Velocidade::vel_atual; }
int Velocidade::getVelMax(){ return Velocidade::vel_max; }

int Velocidade::acelerar(int &velocidade){
    int somaVelocidades = Velocidade::getVelAtual() + velocidade; 
    Velocidade::setVelAtual(((somaVelocidades) >= Velocidade::getVelMax()) ? Velocidade::getVelMax() : somaVelocidades);
}

int Velocidade::travar(int &velocidade){
    int subtracaoVelocidades = Velocidade::getVelAtual() - velocidade;
    Velocidade::setVelAtual(((subtracaoVelocidades) <= 0) ? 0 : subtracaoVelocidades);
}

