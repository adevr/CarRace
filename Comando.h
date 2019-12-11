/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   EntidadeReguladoraAutodromos.h
  * Author: Alex Reis
  *
  * Created on 09 de dezembro de 2019, 11:30
  */

#ifndef COMANDO_H
#define COMANDO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>
#include <sstream>

#include "Consola.h"
#include "DirecaoGeralViacao.h"
#include "EntidadeReguladoraAutodromos.h"


using namespace std;

class Comando
{
    DirecaoGeralViacao* dgv;
    EntidadeReguladoraAutodromos* era;
public:
    Comando(DirecaoGeralViacao* dgv, EntidadeReguladoraAutodromos* era);

    void carregaA(string filename);
    void carregaP(string filename);
    void carregaC(string filename);
    
    void cria(istringstream &info);
    void apaga(istringstream &info);

    void pilotoEntraNoCarro(istringstream &info);
    void pilotoSaiDoCarro(istringstream &info);

    void lista();
    void ajuda();

    DirecaoGeralViacao* getDGV();
    EntidadeReguladoraAutodromos* getERA();
};

#endif /* COMANDO_H */