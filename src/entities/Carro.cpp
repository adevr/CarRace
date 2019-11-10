//
// Created by Alex Reis on 02/11/2019.
//

#include "../headers/Carro.h"

void Carro::setMarca(string marca) { Carro::marca = marca; }
void Carro::setModelo(string modelo) { Carro::modelo = modelo; }

Carro::Carro(string marca, string modelo = "Modelo Base", int capMax, int capIni, int velMax, int estado) {
    Carro::setMarca(marca);
    Carro::setModelo(modelo);
    
    Carro::bateria = Bateria(capMax, capIni); 
    Carro::sinal  = SinalEmergencia();
    Carro::velocidade = Velocidade(velMax);
}
