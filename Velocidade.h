/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Velocidade.h
 * Author: Alex Reis
 *
 * Created on 21 de novembro de 2019, 21:36
 */

#ifndef VELOCIDADE_H
#define VELOCIDADE_H

class Velocidade{
    int vel_max;
    int vel_atual;
public:
    Velocidade(int vel_max);
    ~Velocidade();
    int getVelMax();
    int getVelAtual();
    int acelerar(int velocidade);
    int travar(int velocidade);
private:
    void setVelMax(int vel_max);
    void setVelAtual(int vel_atual);
};

#endif /* VELOCIDADE_H */

