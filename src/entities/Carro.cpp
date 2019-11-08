//
// Created by Alex Reis on 02/11/2019.
//

#include "../headers/Carro.h"

void Carro::setMarca(string marca) { Carro::marca = marca; }
void Carro::setModelo(string modelo) { Carro::modelo = modelo; }
void Carro::setID() {

}

Carro::Carro(string marca, string modelo = "Modelo Base") {
    Carro::setMarca(marca);
    Carro::setModelo(modelo);
    Carro::setID();
}
