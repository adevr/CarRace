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
#include <iostream>
#include <string>
#include "Piloto.h"

using namespace std;

string Piloto::getNome() { return Piloto::nome; }
Carro * Piloto::getCarro(){ return Piloto::carro; }

string Piloto::getAsString(){
    ostringstream oss;
    oss << "Nome: " << getNome();
    
    return oss.str();
}

void Piloto::entraCarro(Carro *c){
    if(Piloto::carro == nullptr || Piloto::carro == 0){
        Piloto::carro = c;
    }else{
        cout << "O carro ja esta ocupado";
    }
}

void Piloto::saiCarro(){
    if(Piloto::carro != nullptr) Piloto::carro = nullptr;
    else cout << "O piloto ja esta fora do carro.";
}

//void Piloto::executaComportamento(){}

Piloto::Piloto(string nome) : nome{nome} {}
Piloto::~Piloto(){}

