/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinalEmergencia.h
 * Author: Alex Reis
 *
 * Created on 21 de novembro de 2019, 21:35
 */

#ifndef SINALEMERGENCIA_H
#define SINALEMERGENCIA_H

class SinalEmergencia{
    bool estado;
public:
    SinalEmergencia();
    ~SinalEmergencia();
    bool getEstado();
private:
    void setEstado(bool estado);
};


#endif /* SINALEMERGENCIA_H */

