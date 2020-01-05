/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Campeonato.h
  * Author: Alex Reis
  *
  * Created on 21 de novembro de 2019, 21:33
  */

#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include <iostream>
#include <vector>
#include <string>

#include "EntidadeReguladoraAutodromos.h"
#include "Carro.h"
#include "Piloto.h"
#include "Corrida.h"

using namespace std;

class Campeonato
{
    vector <Autodromo *> autodromos;
    vector <Carro*> carros;
    vector <Piloto*> pilotos;
    vector <bool> estados;
    vector <string> classCampeonato;
    string nome;
public:
    Campeonato();
    void iniciarProximaCorrida();
    string getClassCampeonato();
    void definirParticipante(Piloto* piloto);
    void setAutodromos(vector <Autodromo*> autodromos);
    vector <Autodromo*> getAutodromos();
    bool avancaTempo(int tempo);
private:
    bool verificaOcurrenciaCorrida(Autodromo *autodromo);

};

#endif /* CAMPEONATO_H */

