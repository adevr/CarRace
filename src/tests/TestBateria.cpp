//
// Created by Alex Reis on 07/11/2019.
//
#include <iostream>
#include "../entities/Bateria.cpp"

using namespace std;

int main(){
    Bateria bateria=  Bateria(100, 35);
    bateria.carregaBateria(200);
    bateria.descarregaBateria(90);
    cout << bateria.getCapAtual() << endl;
}


