/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carro.cpp
 * Author: Alex Reis
 * 
 * Created on 21 de novembro de 2019, 21:28
 */

#include <string>
#include "Carro.h"

void Carro::setMarca(string marca) { Carro::marca = marca; }
void Carro::setModelo(string modelo) { Carro::modelo = modelo; }
//void Carro::setBateria(Bateria bateria) { Carro::bateria = bateria; }
string Carro::getMarca(){ return Carro::marca; }

Carro::Carro(string marca, string modelo, int capMax, int capIni, int velMax, int estado){
    setMarca(marca);
    if(modelo.empty()) setModelo("Modelo Base");
    else setModelo(modelo);
    
    //bateria = Bateria();
    /*
    Carro::bateria  
    Carro::sinal  = SinalEmergencia();
    Carro::velocidade = Velocidade(velMax); */
}
