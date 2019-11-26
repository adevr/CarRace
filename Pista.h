/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pista.h
 * Author: Alex Reis
 *
 * Created on 24 de novembro de 2019, 19:50
 */

#ifndef PISTA_H
#define PISTA_H
#include "DirecaoGeralViacao.h"

class Pista {
    int comprimento;
   // Corrida * corrida;
    DirecaoGeralViacao * dgv;
public:
    Pista(int comprimento);
    Pista(const Pista& orig);
    virtual ~Pista();
private:

};

#endif /* PISTA_H */

