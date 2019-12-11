/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   EntidadeReguladoraAutodromos.h
  * Author: Alex Reis
  *
  * Created on 05 de dezembro de 2019, 11:30
  */

#ifndef ENTIDADEREFULADORAAUTODROMOS_H
#define ENTIDADEREFULADORAAUTODROMOS_H

#include <string>
#include <vector>
#include "Autodromo.h"

class EntidadeReguladoraAutodromos {
private:
    int eraID;
    vector<Autodromo*> autodromos;
public:
    EntidadeReguladoraAutodromos(int eraID);
   
    vector<Autodromo*> getAutodromos();
    Autodromo* novoAutodromo(string nome, int capacidade, int tamanho);
    Autodromo* procuraAutodromo(string nome);
    Autodromo* apagaAutodromo(string nome);

};

#endif /* ENTIDADEREFULADORAAUTODROMOS_H */