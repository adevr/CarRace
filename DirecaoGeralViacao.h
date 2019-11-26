/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DirecaoGeralViacao.h
 * Author: Alex Reis
 *
 * Created on 23 de novembro de 2019, 11:30
 */

#ifndef DIRECAOGERALVIACAO_H
#define DIRECAOGERALVIACAO_H

#include <string>
#include <vector>
#include "Piloto.h"
#include "Carro.h"
#include "Autodromo.h"

class DirecaoGeralViacao {
    int dgvID;
    vector<Piloto *> pilotos;
    vector<Carro *> carros;
    vector<Autodromo *> autodromos;
public:
    DirecaoGeralViacao(int id);
    
    Piloto * novoPiloto(string nome);
    Piloto * procuraPiloto(string nome);
    void carregaP(string file);
    
    Carro * novoCarro(int capInit, int capMax, string marca, string modelo, int velMax, int estado);
    Carro * procuraCarro(string nome);
    void carregaC(string file);
    
    Autodromo * novoAutodromo();
    Autodromo * procuraAutodromo();
    void carregaA(string file);
    
    vector<Piloto*> getPilotos() const { return pilotos;}
    vector<Carro*> getCarros() const { return carros;}
    vector<Autodromo*> getAutodromos() const{return autodromos;}
};

#endif /* DIRECAOGERALVIACAO_H */

