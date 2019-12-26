/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autodromo.cpp
 * Author: Alex Reis
 * 
 * Created on 24 de novembro de 2019, 15:30
 */

#include "Autodromo.h"

void Autodromo::setNome(string nome){ Autodromo::nome = nome; }
void Autodromo::setTamanho(int tamanho){ Autodromo::tamanho = tamanho; }

string Autodromo::getNome() const {return Autodromo::nome;}
int Autodromo::getTamanho() const {return Autodromo::tamanho;}

Autodromo::Autodromo(string nome, int capacidade, int tamanho) : pista(tamanho,capacidade){
    setNome(nome);
    setTamanho(tamanho);
}

string Autodromo::getAsString(){
    ostringstream oss;
    oss << "Nome: " << getNome() << " Tamanho: " << getTamanho();
    
    return oss.str();
}
Autodromo::~Autodromo() {
}


Corrida* Autodromo::getCorrida() const
{
    return corrida;
}
