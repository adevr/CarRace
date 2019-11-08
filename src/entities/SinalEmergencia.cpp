//
// Created by Alex Reis on 02/11/2019.
//

#include "../headers/SinalEmergencia.h"

void SinalEmergencia::setEstado(bool estado){ SinalEmergencia::estado = estado; }
bool SinalEmergencia::getEstado(){ return SinalEmergencia::estado; }

SinalEmergencia::SinalEmergencia(){
    SinalEmergencia::setEstado(false);
}