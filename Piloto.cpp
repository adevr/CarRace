/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Piloto.cpp
 * Author: Alex Reis
 * 
 * Created on 21 de novembro de 2019, 21:25
 */

#include <string>
#include "Piloto.h"

string Piloto::getNome() { return Piloto::nome; }
void Piloto::entraCarro(){
    if(carro == nullptr){
        /*
         * escolher em qual carro entrar.
         * ter em atenção o id do carro .
         */
    }
}

//void Piloto::executaComportamento(){}

Piloto::Piloto(string nome) : nome{nome} {}
Piloto::~Piloto(){}

