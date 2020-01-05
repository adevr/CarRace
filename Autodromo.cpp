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

void Autodromo::setNome(string nome) { Autodromo::nome = nome; }
string Autodromo::getNome() const {return Autodromo::nome;}


Autodromo::Autodromo(string nome, int capacidade, int tamanho) {
    setNome(nome);
    vector<Piloto*> participantes;
    Autodromo::pista = new Pista(tamanho, capacidade, participantes);
}

string Autodromo::getAsString(){
    ostringstream oss;
    oss << "Nome: " << getNome();
    
    return oss.str();
}
Autodromo::~Autodromo() {
}

Pista* Autodromo::getPista() const
{
    return Autodromo::pista;
}

