/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Corrida.h
 * Author: Alex Reis
 *
 * Created on 24 de novembro de 2019, 20:48
 */

#ifndef CORRIDA_H
#define CORRIDA_H

class Corrida {
    bool estado;
public:
    Corrida();
    Corrida(const Corrida& orig);
    virtual ~Corrida();
    
    void toggleCorrida(bool estado);
private:
    bool __comecou();
};

#endif /* CORRIDA_H */

