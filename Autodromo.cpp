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

void Autodromo::setCapacidade(int capacidade){ Autodromo::capacidade = capacidade; }
void Autodromo::setNome(string nome){ Autodromo::nome = nome; }
void Autodromo::setTamanho(int tamanho){ Autodromo::tamanho = tamanho; }

Autodromo::Autodromo(string nome, int capacidade, int tamanho) {
    setNome(nome);
    setCapacidade(capacidade);
    setTamanho(tamanho);
}

Autodromo::~Autodromo() {
}

