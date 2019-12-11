/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   EntidadeReguladoraAutodromos.cpp
  * Author: Alex Reis
  *
  * Created on 05 de dezembro de 2019, 11:30
  */

#include <fstream>
#include <ostream>
#include <sstream>

#include <iostream>
#include <vector>
#include "EntidadeReguladoraAutodromos.h"
#include "helper.h"


using namespace std;
using namespace helper;


EntidadeReguladoraAutodromos::EntidadeReguladoraAutodromos(int eraID)
{
    EntidadeReguladoraAutodromos::eraID = eraID;
}

Autodromo* EntidadeReguladoraAutodromos::procuraAutodromo(string nome) {
    for (vector<Autodromo*>::const_iterator it = autodromos.cbegin();
        it != autodromos.cend();
        it++)
        if ((*it)->getNome() == nome)
            return *it;
    return nullptr;
}

Autodromo* EntidadeReguladoraAutodromos::apagaAutodromo(string nome) {
    if (procuraAutodromo(nome) != nullptr) {
        for (size_t i = 0; i < autodromos.size(); i++) {
            if (autodromos[i]->getNome() == nome) {
                delete autodromos[i];
                autodromos.erase(autodromos.begin() + i);
            }
        }
    }
    return nullptr;
}

Autodromo* EntidadeReguladoraAutodromos::novoAutodromo(string nome, int capacidade, int tamanho) {
    if (procuraAutodromo(nome) != nullptr) nome = rewriteNome(nome);

    if (procuraAutodromo(nome) == nullptr) {
        Autodromo* a = new Autodromo(nome, capacidade, tamanho);
        autodromos.push_back(a);
        return a;
    }
    return nullptr;
}

vector<Autodromo*> EntidadeReguladoraAutodromos::getAutodromos() 
{
    return EntidadeReguladoraAutodromos::autodromos;
}