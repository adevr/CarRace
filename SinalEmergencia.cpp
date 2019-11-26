/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinalEmergencia.cpp
 * Author: Alex Reis
 * 
 * Created on 21 de novembro de 2019, 21:35
 */

#include "SinalEmergencia.h"

void SinalEmergencia::setEstado(bool estado){ SinalEmergencia::estado = estado; }
bool SinalEmergencia::getEstado(){ return SinalEmergencia::estado; }

SinalEmergencia::SinalEmergencia(){
    SinalEmergencia::setEstado(false);
}
