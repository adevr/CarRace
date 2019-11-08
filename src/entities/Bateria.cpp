//
// Created by Alex Reis on 02/11/2019.
//

#include "../headers/Bateria.h"

void Bateria::setCapMax(int cap_max){ Bateria::cap_max = cap_max; }
void Bateria::setCapInit(int cap_init){ Bateria::cap_init = cap_init; }
void Bateria::setCapAtual(int cap_atual){ Bateria::cap_atual = cap_atual; }
int Bateria::getCapAtual() { return Bateria::cap_atual; }

void Bateria::carregaBateria(int quantidade){
    int mah = Bateria::getCapAtual() + quantidade;

    if(mah >= 100) Bateria::setCapAtual(100);
    else Bateria::setCapAtual(mah);
}

void Bateria::descarregaBateria(int quantidade){
    int mah = Bateria::getCapAtual() - quantidade;
    
    if(mah <= 0) Bateria::setCapAtual(0);
    else Bateria::setCapAtual(mah);
}

Bateria::Bateria(int cap_max, int cap_init){
    Bateria::setCapMax(cap_max);
    Bateria::setCapInit(cap_init);
    Bateria::setCapAtual(cap_init);
}

Bateria::~Bateria(){}

