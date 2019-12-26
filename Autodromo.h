/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autodromo.h
 * Author: Alex Reis
 *
 * Created on 24 de novembro de 2019, 15:29
 */

#ifndef AUTODROMO_H
#define AUTODROMO_H
#include <sstream>
#include <string>
#include "Pista.h"
#include "Garagem.h"

using namespace std;

class Autodromo {
    Pista* pista;
    //Garagem garagem;
    string nome;
public:
    Autodromo(string nome, int capacidade, int tamanho);
    ~Autodromo();
    void setNome(string nome);
    string getNome() const;
    string getAsString();
    Pista* getPista() const;
};

#endif /* AUTODROMO_H */

