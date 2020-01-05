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
#include <sstream>
#include "Carro.h"


using namespace std;

class Piloto {
    Carro *carro;
    int tempo;
    int distanciaPercorrida;
    bool morto = false;
    int pontuacao;
protected:
    string nome;
    
public:
    Piloto(string nome);
    ~Piloto();
    string getNome();
    Carro* getCarro();
    void entraCarro(Carro *c);
    void saiCarro();
    string getAsString();

    void para();
    int passatempo(int tempo);
    void setDistanciaPercorrida(int dist);
    int getTempo() const;
    void setTempo(int tempo);
    int getDistanciaPercorrida() const;

    int getPontuacao();
    void setPontuacao(int pontuacao);

    bool morre();

    virtual int executaComportamento(int tempo) = 0;
};
#endif /* PILOTO_H */

