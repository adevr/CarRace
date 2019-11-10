//
// Created by Alex Reis on 07/11/2019.
//
#include <iostream>
#include "../entities/Velocidade.cpp"

using namespace std;

int main(){
    Velocidade velocidade = Velocidade(180);
    velocidade.acelerar(200);
    cout << "Acelerando a 200m/s .. Velocidade Atual " << velocidade.getVelAtual() << endl;
    velocidade.travar(100);
    cout << "Travando.. Velocidade atual " << velocidade.getVelAtual() << endl;
}


