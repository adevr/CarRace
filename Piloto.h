/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Piloto.h
 * Author: Alex Reis
 *
 * Created on 21 de novembro de 2019, 21:25
 */

#ifndef PILOTO_H
#define PILOTO_H

#include <string>
#include "Carro.h"


using namespace std;

class Piloto {
    Carro *carro;
protected:
    string nome;
    
public:
    Piloto(string nome);
    ~Piloto();
    string getNome();
    void entraCarro(Carro *c);
    void saiCarro();
        

    //virtual void executaComportamento();
};
#endif /* PILOTO_H */

