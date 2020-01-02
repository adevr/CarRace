/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DirecaoGeralViacao.cpp
 * Author: Alex Reis
 * 
 * Created on 23 de novembro de 2019, 11:30
 */

#include <fstream>
#include <ostream>
#include <sstream>

#include <iostream>
#include <vector>

#include "helper.h"
#include "DirecaoGeralViacao.h"


using namespace std;
using namespace helper;


DirecaoGeralViacao::DirecaoGeralViacao(int id) {
    DirecaoGeralViacao::dgvID = id;
}

Piloto * DirecaoGeralViacao::procuraPiloto(string nome){
    for (vector<Piloto *>::const_iterator it = pilotos.cbegin();
            it != pilotos.cend();
            it++)
        if ((*it)->getNome() == nome)
            return *it;
    return nullptr;
}
Piloto * DirecaoGeralViacao::novoPiloto(string nome, string tipo){

    if (procuraPiloto(nome) != nullptr){
        nome = rewriteNome(nome);
        novoPiloto(nome, tipo);
    }else if (procuraPiloto(nome) == nullptr) {
        Piloto* p;
        if (tipo == "Crazy") {
            p = new Crazy(nome);
        }
        else if (tipo == "Rapido") {
            p = new Rapido(nome);
        }
        pilotos.push_back(p);
        return p;
    }  
    return nullptr;
}
Piloto * DirecaoGeralViacao::apagaPiloto(string nome){
    if(procuraPiloto(nome) !=  nullptr){
        for(size_t i=0; i < pilotos.size(); i++){
            if(pilotos[i]->getNome() == nome) {
                delete pilotos[i];
                pilotos.erase(pilotos.begin() + i);
            }
        }
    }
    return nullptr;
}

Carro * DirecaoGeralViacao::procuraCarro(char id){
        for (vector<Carro *>::const_iterator it = carros.cbegin();
            it != carros.cend();
            it++)
        if ((*it)->getID() == id)
            return *it;
    return nullptr;
}
Carro * DirecaoGeralViacao::novoCarro(int capInit, int capMax, string marca, string modelo, int velMax, int estado, char id){
    id = rewriteID(id);
    if (procuraCarro(id) != nullptr) novoCarro(capInit, capMax, marca, modelo, velMax, estado, id);
    
    if (procuraCarro(id) == nullptr) {
        Carro * c = new Carro(marca, modelo,capMax, capInit,velMax,estado, id);
        carros.push_back(c);
        return c;
    }
    return nullptr;
}
Carro * DirecaoGeralViacao::apagaCarro(char id){
    if(procuraCarro(id) != nullptr){
        for(size_t i=0; i < carros.size(); i++){
            if(carros[i]->getID() == id){
                delete carros[i];
                carros.erase(carros.begin()+i);
            }
        }
    }
    return nullptr;
}


