//
// Created by Alex Reis on 02/11/2019.
//

#include "../headers/Piloto.h"

void Piloto::setNome(string nome) { Piloto::nome = nome; }

Piloto::Piloto(string nome){
    Piloto::setNome(nome);
}