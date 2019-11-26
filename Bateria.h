/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bateria.h
 * Author: Alex Reis
 *
 * Created on 21 de novembro de 2019, 21:33
 */

#ifndef BATERIA_H
#define BATERIA_H

class Bateria{
    int cap_max;
    int cap_init;
    int cap_atual;
public:
    Bateria(int cap_max, int cap_init);
    ~Bateria();
    void carregaBateria(int quantidade = 0);
    void descarregaBateria(int quantidade = 0);
    int getCapAtual();
private:
    void setCapMax(int cap_max);
    void setCapInit(int cap_init);
    void setCapAtual(int cap_atual);
};


#endif /* BATERIA_H */

