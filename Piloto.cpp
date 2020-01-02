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
    if (carro != nullptr) oss << "Nome: " << getNome() << "  -> " << "Carro: " << carro->getMarca() << " " << carro->getModelo();
    else oss << "Nome: " << getNome();

    return oss.str();
}

void Piloto::entraCarro(Carro *c){
    if(Piloto::carro == nullptr){
        Piloto::carro = c;
    }else{
        cout << "O carro ja esta ocupado";
    }
}

void Piloto::saiCarro(){
    if(Piloto::carro != nullptr) Piloto::carro = nullptr;
    else cout << "O piloto ja esta fora do carro.";
}


Piloto::Piloto(string nome) : nome{nome} 
{
    Piloto::carro = nullptr;
}
Piloto::~Piloto(){}


void Piloto::para() 
{
    if (Piloto::carro != nullptr){
        Velocidade* v = Piloto::carro->getVelocidade();
        v->travar(v->getVelAtual());
    }
}

int Piloto::passatempo(int tempo) 
{
    Piloto::distanciaPercorrida = distanciaPercorrida+tempo;
    Piloto::tempo += tempo;
    return distanciaPercorrida;
}

void Piloto::setDistanciaPercorrida(int dist)
{
    Piloto::distanciaPercorrida = dist;
}

int Piloto::getTempo() const 
{
    return Piloto::tempo;
}

void Piloto::setTempo(int tempo)
{
    Piloto::tempo += tempo;
}

int Piloto::getDistanciaPercorrida() const
{
    return Piloto::distanciaPercorrida;
}